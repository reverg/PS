import sys

input = sys.stdin.readline


# O(N)
def palindrome_permutation(phrase):
    """function checks if a string is a permutation of a palindrome or not"""
    table = [0 for _ in range(ord("z") - ord("a") + 1)]
    countodd = 0
    for c in phrase:
        x = char_number(c)
        if x != -1:
            table[x] += 1
            if table[x] % 2:
                countodd += 1
            else:
                countodd -= 1

    return countodd <= 1


def char_number(c):
    # do not care upper/lower case
    a = ord("a")
    z = ord("z")
    A = ord("A")
    Z = ord("Z")
    val = ord(c)

    if a <= val <= z:
        return val - a
    elif A <= val <= Z:
        return val - A
    return -1


if __name__ == "__main__":
    while True:
        try:
            s = input().rstrip()
            ans = palindrome_permutation(s)
            print(ans)
        except EOFError:
            break
