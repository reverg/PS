import sys

input = sys.stdin.readline


if __name__ == "__main__":
    E, S, M = map(int, input().split())
    year, e, s, m = 1, 1, 1, 1

    while True:
        if e == E and s == S and m == M:
            break

        year += 1
        e = e % 15 + 1
        s = s % 28 + 1
        m = m % 19 + 1

    print(year)
