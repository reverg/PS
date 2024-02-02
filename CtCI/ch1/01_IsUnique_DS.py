# O(n) solutions with arrays
import sys

input = sys.stdin.readline


def is_unique_with_array(s):
    # Assuming character set is ASCII (128 characters)
    if len(s) > 128:
        return False

    char_set = [False for _ in range(128)]
    for c in s:
        val = ord(c)
        if char_set[val]:
            return False
        char_set[val] = True

    return True


def is_unique_with_bitvector(s):
    # Assuming character set is ASCII (128 characters)
    if len(s) > 128:
        return False

    checker = 0
    for c in s:
        val = ord(c)
        if checker & (1 << val):
            return False
        checker |= 1 << val

    return True


if __name__ == "__main__":
    while True:
        try:
            s = input().rstrip()
            ans = is_unique_with_bitvector(s)
            print(ans)
        except EOFError:
            break
