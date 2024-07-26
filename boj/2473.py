# Solution with Three Pointers
# Very simillar to 2467, check two solutions of it

import sys

input = sys.stdin.readline

N = int(input())
liquids = list(map(int, input().split()))
liquids.sort()

min_character = 3000000000
ans1, ans2, ans3 = 0, 0, 0

for i in range(N - 2):
    ptr1 = i
    ptr2 = i + 1
    ptr3 = N - 1

    while ptr2 < ptr3:
        tmp = liquids[ptr1] + liquids[ptr2] + liquids[ptr3]
        if abs(tmp) < min_character:
            min_character = abs(tmp)
            ans1, ans2, ans3 = liquids[ptr1], liquids[ptr2], liquids[ptr3]

        if tmp == 0:
            break
        elif tmp < 0:
            ptr2 += 1
        else:
            ptr3 -= 1

print(ans1, ans2, ans3)
