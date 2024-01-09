# Solution with Two Pointers

import sys

input = sys.stdin.readline

N = int(input())
liquids = list(map(int, input().split()))

left_ptr = 0
right_ptr = N - 1

min_character = abs(liquids[left_ptr] + liquids[right_ptr])
sol1 = left_ptr
sol2 = right_ptr

while left_ptr < right_ptr:
    tmp = liquids[left_ptr] + liquids[right_ptr]

    if abs(tmp) < min_character:
        sol1 = left_ptr
        sol2 = right_ptr
        min_character = abs(tmp)

        if min_character == 0:
            break

    if tmp < 0:
        left_ptr += 1

    else:
        right_ptr -= 1

print(liquids[sol1], liquids[sol2])
