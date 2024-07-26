import re

# 변수명 입력 받기
variable_name = input().strip()

# 변수명 형식 확인하기
is_java = variable_name[0].islower() and "_" not in variable_name
is_cpp = variable_name.islower() and re.search(r"_", variable_name) is not None

# 변수명 변환하기
if is_java:
    # Java -> C++
    converted = ""
    for i, char in enumerate(variable_name):
        if char.isupper() and i > 0:
            converted += "_"
        converted += char.lower()
    print(converted)
elif is_cpp:
    # C++ -> Java
    words = variable_name.split("_")
    if any(word == "" for word in words):
        print("Error!")
    else:
        converted = words[0] + "".join(word.capitalize() for word in words[1:])
        print(converted)
else:
    print("Error!")
