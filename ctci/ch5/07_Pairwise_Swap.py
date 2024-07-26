import sys

input = sys.stdin.readline


def logical_shift_right(x, n):
    # Ensure x is treated as an unsigned 32-bit integer
    return (x % 0x100000000) >> n


def swapOddEvenBits(n):
    return logical_shift_right(n & 0xAAAAAAAA, 1) | ((n & 0x55555555) << 1)


if __name__ == "__main__":
    N = int(input())

    N_swap = swapOddEvenBits(N)

    print(format(N & 0xFFFFFFFF, "b"))
    print(format(N_swap & 0xFFFFFFFF, "b"))
