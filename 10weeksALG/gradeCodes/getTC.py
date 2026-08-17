import re
import sys


def convert_to_cpp_vector(text: str) -> str:
    # '프라이빗 입력 N'과 '프라이빗 출력 N' 패턴 매칭
    pattern = re.compile(
        r"프라이빗 입력 \d+\s*\n(.*?)\s*프라이빗 출력 \d+\s*\n(.*?)(?=\n\s*프라이빗 입력 \d+|\Z)",
        re.DOTALL,
    )

    matches = pattern.findall(text)
    test_cases = []

    def escape_cpp_string(s: str) -> str:
        s = s.strip("\r\n")
        if s:
            s += "\n"
        s = s.replace("\\", "\\\\")
        s = s.replace('"', '\\"')
        s = s.replace("\n", "\\n")
        s = s.replace("\r", "")
        s = s.replace("\t", "\\t")
        return s

    for inp, out in matches:
        escaped_inp = escape_cpp_string(inp)
        escaped_out = escape_cpp_string(out)
        test_cases.append(f'    {{"{escaped_inp}", "{escaped_out}"}}')

    result = "vector<TestCase> test_cases = {\n" + ",\n".join(test_cases) + "\n};"
    return result

if __name__ == "__main__":
    with open("input.txt", "r", encoding="utf-8") as f:
        raw_input = f.read()

    print(convert_to_cpp_vector(raw_input))
    