import sys


def rec(s, start):
    global ans

    if not s:
        return

    min_char = min(s)
    min_idx = s.index(min_char)
    ans[start + min_idx] = min_char
    print("".join(ans))

    rec(s[min_idx + 1 :], start + min_idx + 1)
    rec(s[:min_idx], start)


chars = list(map(str, sys.stdin.readline().rstrip()))
ans = [""] * len(chars)
rec(chars, 0)
