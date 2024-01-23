import sys
from collections import Counter

input = sys.stdin.readline


def check_permutation(str1, str2):
    if len(str1) != len(str2):
        return False

    """
    counter = Counter()
    for c in str1:
        counter[c] += 1
    for c in str2:
        if counter[c] == 0:
            return False
        counter[c] -= 1
    return True
    """

    counter1 = Counter(str1)
    counter2 = Counter(str2)

    if sorted(counter1.elements()) == sorted(counter2.elements()):
        return True
    else:
        return False


if __name__ == "__main__":
    while True:
        try:
            str1 = input().rstrip()
            str2 = input().rstrip()
            ans = check_permutation(str1, str2)
            print(ans)
        except EOFError:
            break
