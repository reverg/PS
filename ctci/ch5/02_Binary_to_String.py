import sys

input = sys.stdin.readline

if __name__ == "__main__":
    num = float(input())

    if num >= 1 or num <= 0:
        print("ERROR")
    else:
        binary = "0."
        isError = False
        while num > 0:
            if len(binary) >= 32:
                isError = True
                break

            r = num * 2
            if r >= 1:
                binary += "1"
                num = r - 1
            else:
                binary += "0"
                num = r

        print(binary + "(2)" if not isError else "ERROR")
