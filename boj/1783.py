import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N, M = map(int, input().split())

    if N == 1:
        print(1)
    elif N == 2:
        print(1 + min(3, (M - 1) // 2))
    else:
        if M < 7:
            print(1 + min(3, M - 1))
        else:
            print(1 + 4 + (M - 7))
