import sys

input = sys.stdin.readline


def logical_shift_right(x, n):
    # Ensure x is treated as an unsigned 32-bit integer
    return (x % 0x100000000) >> n


def bitSwapRequired(a, b):
    count = 0
    c = a ^ b
    while c != 0:
        count += c & 1
        c = logical_shift_right(c, 1)
        # c = c & (c-1) not works well for negative integers in python
    return count


if __name__ == "__main__":
    A, B = map(int, input().split())

    print(bitSwapRequired(A, B))
