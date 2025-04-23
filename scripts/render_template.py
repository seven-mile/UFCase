import sys
from pathlib import Path
import xml.etree.ElementTree as ET

def get_localname(node):
    return node.tag.split('}')[-1] if '}' in node.tag else node.tag

def parse_vars(var_file):
    with open(var_file, 'r', encoding='utf-8') as f:
        xml_str = f.read()
    # 因为传入的是多个同级节点，需要包装一个根节点
    wrapped_xml = f"<root>{xml_str}</root>"
    root = ET.fromstring(wrapped_xml)
    
    result = {}
    for child in root:
        result[get_localname(child)] = child.text
    return result

def render_template(template_path, variables, output_path=None):
    template_path = Path(template_path)
    if not template_path.exists():
        print(f"模板文件 {template_path} 不存在。")
        return

    if output_path is None:
        output_path = template_path.with_suffix('')  # 去掉 .in 后缀
    else:
        output_path = Path(output_path)

    content = template_path.read_text(encoding='utf-8')

    for key, value in variables.items():
        # 普通替换：${{key}}
        placeholder = f"${{{{{key}}}}}"
        content = content.replace(placeholder, value)

        # 文件内容替换：$[[key]]
        file_placeholder = f"$[[{key}]]"
        if file_placeholder in content:
            file_path = Path(value)
            if file_path.exists():
                file_content = file_path.read_text(encoding='utf-8')
                content = content.replace(file_placeholder, file_content)
            else:
                print(f"警告: 用于 $[[{key}]] 的文件 {value} 不存在")

    output_path.write_text(content, encoding='utf-8')
    print(f"生成文件: {output_path}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("用法: python render.py <模板文件.in> <字典文件.var> [输出文件]")
    else:
        template_file = sys.argv[1]
        variables = parse_vars(sys.argv[2])
        output_file = sys.argv[3] if len(sys.argv) > 3 else None
        # print(f"解析变量: {variables}")
        render_template(template_file, variables, output_file)
