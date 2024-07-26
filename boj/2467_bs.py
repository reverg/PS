# Solution with Binary Search

import sys

input = sys.stdin.readline

N = int(input())
liquids = list(map(int, input().split()))

min_character = 2000000000
sol1, sol2 = 0, 0

for i in range(N - 1):
    cur_sol = liquids[i]
    low = i + 1
    high = N - 1

    while low <= high:
        mid = (low + high) // 2
        tmp = cur_sol + liquids[mid]

        if abs(tmp) < min_character:
            min_character = abs(tmp)
            sol1 = liquids[i]
            sol2 = liquids[mid]
            if tmp == 0:
                break

        if tmp < 0:
            low = mid + 1
        else:
            high = mid - 1

print(sol1, sol2)
