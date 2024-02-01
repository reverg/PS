import sys
from itertools import permutations

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    arr = list(map(int, input().split()))

    perm = permutations(arr)
    ans = 0

    for p in perm:
        sum = 0
        for i in range(len(arr) - 1):
            sum += abs(p[i + 1] - p[i])
        if ans < sum:
            ans = sum

    print(ans)
