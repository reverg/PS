import sys
from itertools import combinations
from collections import OrderedDict

input = sys.stdin.readline

# Meet in the middle: split numbers to two lists and count pairs that sum is S
N, S = map(int, input().split())
nums = list(map(int, input().split()))
part1 = nums[: N // 2]
part2 = nums[N // 2 :]
part1_sums = OrderedDict()
part2_sums = OrderedDict()

# Get sums of all combinations
for r in range(len(part1) + 1):
    for com in combinations(part1, r):
        sum_com = sum(com)
        part1_sums[sum_com] = part1_sums.get(sum_com, 0) + 1
for r in range(len(part2) + 1):
    for com in combinations(part2, r):
        sum_com = sum(com)
        part2_sums[sum_com] = part2_sums.get(sum_com, 0) + 1
part1_sums = OrderedDict(sorted(part1_sums.items()))
part2_sums = OrderedDict(sorted(part2_sums.items(), reverse=True))

# Count pairs using two pointers
cnt = 0
lptr, rptr = 0, 0
part1_sum_keys = list(part1_sums.keys())
part2_sum_keys = list(part2_sums.keys())
while lptr < len(part1_sums) and rptr < len(part2_sums):
    lval = part1_sum_keys[lptr]
    rval = part2_sum_keys[rptr]
    if lval + rval > S:
        rptr += 1
    elif lval + rval < S:
        lptr += 1
    else:
        cnt += part1_sums[part1_sum_keys[lptr]] * part2_sums[part2_sum_keys[rptr]]
        lptr += 1
        rptr += 1

if S == 0:
    print(cnt - 1)  # exclude empty set
else:
    print(cnt)
