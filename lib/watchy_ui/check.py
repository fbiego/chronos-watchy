import os
import re
import xml.etree.ElementTree as ET

# Map XML types to expected expression patterns
TYPE_PATTERNS = {
    "string": r"value",
    "arglist": r"value",
    "obj": r"value",
    "image": r"lv_xml_get_image\(&state->scope,\s*value\)",
    "font": r"lv_xml_get_font\(&state->scope,\s*value\)",
    "int": r"(lv_xml_to_size|lv_xml_atoi)\(value\)",
    "bool": r"lv_xml_to_bool\(value\)",
    "color": r"lv_xml_to_color\(value\)",
    "subject": r"lv_xml_get_subject\(&state->scope,\s*value\)",
}

TYPE_PATT = {
    "string": "value",
    "arglist": "value",
    "obj": "value",
    "image": "lv_xml_get_image(&state->scope, value)",
    "font": "lv_xml_get_font(&state->scope, value)",
    "int": "lv_xml_to_size(value)",
    "bool": "lv_xml_to_bool(value)",
    "color": "lv_xml_to_color(value)",
    "subject": "lv_xml_get_subject(&state->scope, value)",
}

def find_files(root_dir, suffix):
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith(suffix):
                yield os.path.join(root, file)

def parse_xml_props(xml_path):
    try:
        tree = ET.parse(xml_path)
        root = tree.getroot()
        api = root.find("api")
        if api is None:
            return []
        props = []
        for prop in api.findall("prop"):
            name = prop.get("name")
            type_ = prop.get("type")
            if name and type_:
                props.append((name, type_))
        return props
    except Exception as e:
        print(f"  ❌ Failed to parse XML {xml_path}: {e}")
        return []

def check_setters(c_path, base_name, props):
    with open(c_path, 'r') as f:
        content = f.read()

    missing = []
    wrong_format = []
    prop_items = []

    for prop_name, prop_type in props:
        setter = f"{base_name}_set_{prop_name}"
        prop_items.append((base_name, prop_type, prop_name))
        val_pattern = TYPE_PATTERNS.get(prop_type)
        if not val_pattern:
            print(f"  ⚠️  Unknown type '{prop_type}' for prop '{prop_name}', skipping.")
            continue
        if prop_type == "subject":
            setter = f"{base_name}_{prop_name}"
        pattern = rf"{setter}\(\s*\w+\s*,\s*{val_pattern}\s*\);"
        if not re.search(pattern, content):
            if setter not in content:
                missing.append((setter, prop_type, prop_name))
            else:
                wrong_format.append((setter, prop_type))

    return missing, wrong_format, prop_items

def main(folder):
    for header_path in find_files(folder, "_private_gen.h"):
        print(f"\n🔍 Checking: {header_path}")

        base_path = header_path.replace("_private_gen.h", "")
        xml_path = base_path + ".xml"
        c_path = base_path + "_xml_parser.c"

        base_name = os.path.basename(base_path)

        if not os.path.exists(xml_path):
            print(f"  ❌ Missing XML file: {xml_path}")
            continue
        if not os.path.exists(c_path):
            print(f"  ❌ Missing parser C file: {c_path}")
            continue

        props = parse_xml_props(xml_path)
        if not props:
            print(f"  ✅  No <prop> entries found in: {xml_path}")
            continue

        missing, wrong_format, prop_it = check_setters(c_path, base_name, props)

        # for prop, type_, name_ in prop_it:
        #     # print(f"void {prop}_set_{name_}(lv_obj_t * {prop}, {type_} {name_})")
        #     # print("{")
        #     print(f"    {prop}_t * widget = ({prop}_t *){prop};")
        #     print(f"    widget->{name_} = {name_};\n")
        #     # print("}")

        if not missing and not wrong_format:
            print("  ✅ All setter calls present and correctly formatted.")
        else:
            for prop, type_, name_ in prop_it:
                # print(f"void {prop}_set_{name_}(lv_obj_t * {prop}, {type_} {name_})")
                # print("{")
                print(f"    {prop}_t * widget = ({prop}_t *){prop};")
                print(f"    widget->{name_} = {name_};\n")
                # print("}")
            if missing:
                print("  ❌ Missing setter calls:")
                for fn, type_, name_ in missing:
                    
                    print(f"if(lv_streq(\"{name_}\", name)) {{")
                    print(f"    {fn}(item, {TYPE_PATT[type_]});")
                    print("}")
            if wrong_format:
                print("  ⚠️  Incorrect format for:")
                for fn, type_ in wrong_format:
                    print(f"    {fn}(item, ???) — expected type: {type_}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 2:
        print("Usage: python check.py <folder>")
    else:
        main(sys.argv[1])
