import sys
from collections import OrderedDict

input = sys.stdin.readline

N = int(input())
input_nums = list(map(int, input().split()))
cards = [(i, input_nums[i]) for i in range(N)]
answer = OrderedDict()
for card in cards:
    answer[card[1]] = 0

cards.sort(key=lambda x: x[1])
max_num = cards[-1][1]

for i in range(N):
    orig_pos, num = cards[i]

    for target in range(num * 2, max_num + 1, num):
        if target in answer:
            answer[num] += 1
            answer[target] -= 1

for key, item in answer.items():
    print(item, end=" ")
