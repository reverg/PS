import sys

input = sys.stdin.readline


# O(N)
def string_compression(s):
    compressed = []
    cnt = 0

    for i in range(len(s)):
        if i != 0 and s[i] != s[i - 1]:
            compressed.append(s[i - 1] + str(cnt))
            cnt = 0
        cnt += 1

    # add last repeated character
    compressed.append(s[-1] + str(cnt))

    # return original string if compressed string is not smaller
    return min(s, "".join(compressed), key=len)


if __name__ == "__main__":
    while True:
        try:
            s = input().rstrip()
            ans = string_compression(s)
            print(ans)
        except EOFError:
            break
