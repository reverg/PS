import sys

input = sys.stdin.readline


if __name__ == "__main__":
    num = input().rstrip()

    if "0" not in num:
        print(-1)
    else:
        num_sum = 0
        for n in num:
            num_sum += int(n)

        if num_sum % 3 != 0:
            print(-1)
        else:
            sorted_num = sorted(num, reverse=True)
            print("".join(sorted_num))
