#    MIT License
#
#   Copyright (c) 2025 Felix Biego
#
#   Permission is hereby granted, free of charge, to any person obtaining a copy
#   of this software and associated documentation files (the "Software"), to deal
#   in the Software without restriction, including without limitation the rights
#   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#   copies of the Software, and to permit persons to whom the Software is
#   furnished to do so, subject to the following conditions:
#
#   The above copyright notice and this permission notice shall be included in all
#   copies or substantial portions of the Software.
#
#   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#   SOFTWARE.
#
#   ______________  _____
#   ___  __/___  /_ ___(_)_____ _______ _______
#   __  /_  __  __ \__  / _  _ \__  __ `/_  __ \ 
#   _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
#   /_/     /_.___/ /_/   \___/ _\__, /  \____/
# 							  /____/
#

import re
import os, shutil
from datetime import datetime
from pathlib import Path
import json

Import("env")

sep = os.sep

FILE_PATH = Path(f"lib{sep}DeviceModule{sep}DeviceModule.h")

print("Merge Script")

def merge_bins(pairs, out_path, new_pairs):
    """
    Merge ESP32 .bin segments into one file starting from the lowest offset.

    pairs: list of (offset, path) tuples (e.g. (0x1000, "bootloader.bin"))
    out_path: output file path
    """

    # Normalize and load
    segs = []
    for off, path in pairs:
        off = int(off, 0) if isinstance(off, str) else off
        with open(path, "rb") as f:
            data = f.read()
        segs.append((off, data, path))

    # Find address bounds
    min_off = min(o for o, _, _ in segs)
    max_end = max(o + len(d) for o, d, _ in segs)
    total_size = max_end - min_off

    out_path = out_path.replace('.bin', f"_0x{min_off:X}.bin")

    print(f"Merging {len(segs)} segments into {out_path}")
    print(f"Start offset: 0x{min_off:X}, total size: {total_size} bytes")

    buf = bytearray([0xFF]) * total_size

    for off, data, path in segs:
        rel_off = off - min_off
        # print(f"  {path}: offset=0x{off:X}, rel=0x{rel_off:X}, size={len(data)}")
        buf[rel_off:rel_off + len(data)] = data

    os.makedirs(os.path.dirname(out_path), exist_ok=True)
    with open(out_path, "wb") as f:
        f.write(buf)

    data = {}
    data["merged"] = {}
    data["merged"]["file"] = f"{out_path.split(sep)[-1]}"
    data["merged"]["address"] = f"0x{min_off:X}"
    data["merged"]["hex"] = min_off

    data["split"] = []
    for off, name in new_pairs:
        off = int(off, 0) if isinstance(off, str) else off
        data["split"].append({
            "file": name,
            "address": f"0x{off:X}",
            "hex": off
        })

    file_path = f"firmware{sep}firmware.json"
    with open(file_path, 'w', encoding='utf-8') as f:
        json.dump(data, f, ensure_ascii=False, indent=4)

    print(f"✅ Wrote merged file: {out_path} ({len(buf)} bytes)")

def read_version(content):
    major = re.search(r'#define\s+CHRONOS_WATCHY_MAJOR\s+(\d+)', content)
    minor = re.search(r'#define\s+CHRONOS_WATCHY_MINOR\s+(\d+)', content)
    patch = re.search(r'#define\s+CHRONOS_WATCHY_PATCH\s+(\d+)', content)
    build = re.search(r'#define\s+CHRONOS_WATCHY_BUILD\s+"(\d+)"', content)
    if not all([major, minor, patch, build]):
        raise ValueError("Missing version fields in file")
    return {
        "major": major.group(1),
        "minor": minor.group(1),
        "patch": patch.group(1),
        "build": build.group(1)
    }

def update_build(content):
    today = datetime.now().strftime("%Y%m%d")
    return re.sub(
        r'#define\s+CHRONOS_WATCHY_BUILD\s+"(\d+)"',
        f'#define CHRONOS_WATCHY_BUILD "{today}"',
        content
    ), today

def run_update(file_path):
    content = file_path.read_text()
    old_version = read_version(content)
    new_content, new_build = update_build(content)

    print(f"Current version: v{old_version['major']}.{old_version['minor']}.{old_version['patch']} ({old_version['build']})")

    if old_version['build'] != new_build:
        file_path.write_text(new_content)
        print(f"Updated build to: {new_build}")

    
def version_utils(file_path):
    content = file_path.read_text()
    version = read_version(content)
    return version


def after_build(source, target, env):
    env_name = str(source[0]).split(sep)[-2]

    dest_dir = f"firmware"
    os.makedirs(dest_dir, exist_ok=True)

    # Remove all files and subfolders inside dest_dir
    for filename in os.listdir(dest_dir):
        file_path = os.path.join(dest_dir, filename)
        try:
            if os.path.isfile(file_path) or os.path.islink(file_path):
                os.remove(file_path)  # remove file or symlink
            elif os.path.isdir(file_path):
                shutil.rmtree(file_path)  # remove directory
        except Exception as e:
            print(f"Failed to delete {file_path}: {e}")

    
    info = version_utils(FILE_PATH)
    vers = f"v{info['major']}.{info['minor']}.{info['patch']}"

    merged_path = f"{dest_dir}{sep}{env_name}_{vers}_{info['build']}_merged.bin"

    # Get full upload command (PlatformIO’s real flash command)
    upload_cmd = env.subst("$UPLOADCMD") + f" {str(source[0])}"

    # print(f"Upload cmd: {upload_cmd}")

    # Parse the chip type
    chip_match = re.search(r"--chip\s+(\S+)", upload_cmd)
    chip = chip_match.group(1) if chip_match else "esp32"

    # Parse offset + .bin pairs
    pairs = re.findall(r"(0x[0-9a-fA-F]+)\s+(\S+\.bin)", upload_cmd)
    if not pairs:
        print("❌ Could not detect any binary segments from upload command!")
        print(upload_cmd)
        return

    new_pairs = []
    # Build the merge command
    cmd = f"esptool.py --chip {chip} merge-bin --format raw -o {merged_path} --flash-mode dio --flash-size 4MB "
    for offset, path in pairs:
        cmd += f"{offset} {path} "
        file_name = path.split(sep)[-1]
        new_name = f"{env_name}_{vers}_{info['build']}_{file_name.replace(".bin", f"_{offset}.bin")}"
        shutil.copyfile(path, dest_dir + f"/{new_name}")
        new_pairs.append((offset,new_name))

    merge_bins(pairs, merged_path, new_pairs) # use custom merge function
    
    # print(f"Command: {cmd}")
    # print("\n=== ESP32 Auto Binary Merge (Post-Build) ===")
    # print(f"Chip: {chip}")
    # for o, p in pairs:
    #     print(f"{o}\t{p}")
    # print(f"Output: {merged_path}")
    # print("===========================================\n")

    # result = env.Execute(cmd)
    # if result == 0:
    #     print(f"✅ Merged binary created successfully: {merged_path}\n")
    # else:
    #     print("❌ Failed to merge binaries.\n")

# Run after main program build
env.AddPostAction("upload", after_build)
env.AddPostAction("buildprog", after_build)

#update
run_update(FILE_PATH)