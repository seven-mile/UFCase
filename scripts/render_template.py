import sys
from pathlib import Path
import xml.etree.ElementTree as ET

def get_localname(node):
    return node.tag.split('}')[-1] if '}' in node.tag else node.tag

def parse_vars(var_file):
    with open(var_file, 'r', encoding='utf-8') as f:
        xml_str = f.read()
    # Since we're passing multiple sibling nodes, wrap them in a root node.
    wrapped_xml = f"<root>{xml_str}</root>"
    root = ET.fromstring(wrapped_xml)
    
    result = {}
    for child in root:
        result[get_localname(child)] = child.text
    return result

def render_template(template_path, variables, output_path=None):
    template_path = Path(template_path)
    if not template_path.exists():
        print(f"Template file {template_path} does not exist.")
        return

    if output_path is None:
        output_path = template_path.with_suffix('')  # Remove .in extension.
    else:
        output_path = Path(output_path)

    content = template_path.read_text(encoding='utf-8')

    for key, value in variables.items():
        # Simple replacement: ${{key}}.
        placeholder = f"${{{{{key}}}}}"
        content = content.replace(placeholder, value)

        # File content replacement: $[[key]].
        file_placeholder = f"$[[{key}]]"
        if file_placeholder in content:
            file_path = Path(value)
            if file_path.exists():
                file_content = file_path.read_text(encoding='utf-8')
                content = content.replace(file_placeholder, file_content)
            else:
                print(f"Warning: File {value} for $[[{key}]] does not exist")

    output_path.write_text(content, encoding='utf-8')
    print(f"Generated file: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python render.py <template_file.in> <variables_file.var> [output_file]")
    else:
        template_file = sys.argv[1]
        variables = parse_vars(sys.argv[2])
        output_file = sys.argv[3] if len(sys.argv) > 3 else None
        # print(f"Parsed variables: {variables}")
        render_template(template_file, variables, output_file)
