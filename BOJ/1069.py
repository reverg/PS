import sys
from math import *

input = sys.stdin.readline


if __name__ == "__main__":
    X, Y, D, T = map(int, input().split())

    distance = dist((X, Y), (0, 0))

    time = 0
    if T > D:  # walking is faster than jumping
        time = distance
    else:
        # case 1: only jump
        time1 = max(ceil(distance / D), 2) * T

        # case 2: jump to origin and walk
        jump_1 = distance // D
        left_dist_1 = distance % D
        time2 = jump_1 * T + left_dist_1

        # case 3: jumping over the origin and walk
        jump_2 = jump_1 + 1
        left_dist_2 = D - left_dist_1
        time3 = jump_2 * T + left_dist_2

        time = min(time1, time2, time3)

    print(time)
