import sys

input = sys.stdin.readline


# O(n^2) but no extra array
def is_unique_without_ds(s):
    for i in range(len(s)):
        for j in range(len(s)):
            if i == j:
                continue
            if s[i] == s[j]:
                return False

    return True


# O(nlogn), but have to change original string
# In fact, python will assign new string, so this uses extra memory
def is_unique_with_sort(s):
    sorted_s = "".join(sorted(s))
    for i in range(len(s) - 1):
        if sorted_s[i] == sorted_s[i + 1]:
            return False

    return True


if __name__ == "__main__":
    while True:
        try:
            s = input().rstrip()
            ans = is_unique_with_sort(s)
            print(ans)
        except EOFError:
            break
