import sys

input = sys.stdin.readline


# Assume O(A+B)
def is_substring(orig, sub):
    return orig.find(sub) != -1


# Then O(N)
def string_rotation(s1, s2):
    if not len(s1) == len(s2):
        return False
    return is_substring(s1 + s1, s2)


if __name__ == "__main__":
    while True:
        try:
            s1, s2 = input().rstrip().split()
            ans = string_rotation(s1, s2)
            print(ans)
        except EOFError:
            break
