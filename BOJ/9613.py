import sys

input = sys.stdin.readline


def gcd(n1, n2):
    if n1 < n2:
        n1, n2 = n2, n1

    while n2 != 0:
        n1, n2 = n2, n1 % n2

    return n1


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        str = list(map(int, input().split()))
        n, nums = str[0], str[1:]

        gcd_sum = 0
        for i in range(n):
            for j in range(i + 1, n):
                gcd_sum += gcd(nums[i], nums[j])

        print(gcd_sum)
