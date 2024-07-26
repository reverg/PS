import sys

input = sys.stdin.readline


def isPalindrome(s: str):
    if len(s) == 1:
        return True

    front_part = s[: len(s) // 2]
    back_part = s[len(s) // 2 :] if len(s) % 2 == 0 else s[len(s) // 2 + 1 :]
    if front_part == back_part[::-1]:
        return isPalindrome(front_part)
    else:
        return False


S = input().rstrip()

if isPalindrome(S):
    print("AKARAKA")
else:
    print("IPSELENTI")
