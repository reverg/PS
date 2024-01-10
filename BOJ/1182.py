import sys
from itertools import combinations

input = sys.stdin.readline

N, S = map(int, input().split())
nums = list(map(int, input().split()))

cnt = 0
for r in range(1, len(nums) + 1):
    for com in combinations(nums, r):
        if sum(com) == S:
            cnt += 1


print(cnt)
