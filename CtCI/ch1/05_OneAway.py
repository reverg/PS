import sys

input = sys.stdin.readline


# O(min(a, b)) ~= O(N)
def one_edit_away(s1, s2):
    if abs(len(s1) - len(s2)) > 1:
        return False

    if len(s1) > len(s2):
        s1, s2 = s2, s1

    idx1, idx2 = 0, 0
    foundDifference = False
    while idx2 < len(s2) and idx1 < len(s1):
        if s1[idx1] != s2[idx2]:  # replace or insert/delete
            if foundDifference:
                return False
            foundDifference = True
            if len(s1) == len(s2):  # replace
                idx1 += 1
        else:
            idx1 += 1
        idx2 += 1

    return True


if __name__ == "__main__":
    while True:
        try:
            s1, s2 = input().rstrip().split()
            ans = one_edit_away(s1, s2)
            print(ans)
        except EOFError:
            break
