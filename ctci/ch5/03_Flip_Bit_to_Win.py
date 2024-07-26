import sys

input = sys.stdin.readline


def arithmetic_shift_right(x, n):
    sign_mask = -1 if x < 0 else 0
    x >>= n
    x &= ~(sign_mask >> n)
    return x


def flipbit(a):
    if ~a == 0:
        return len(bin(a)) - 2

    curr_len, prev_len = 0, 0
    max_len = 1

    while a:
        if a & 1 == 1:
            curr_len += 1
        elif a & 1 == 0:
            prev_len = 0 if (a & 2) == 0 else curr_len
            curr_len = 0
        max_len = max(prev_len + curr_len + 1, max_len)
        a = arithmetic_shift_right(a, 1)

    return max_len


if __name__ == "__main__":
    num = int(input())
    print(bin(num))

    # only works for negative number
    # need to check python negative integer representations
    print(flipbit(num))
