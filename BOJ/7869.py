import sys
from math import *

input = sys.stdin.readline


if __name__ == "__main__":
    x1, y1, r1, x2, y2, r2 = map(float, input().split())

    d = dist((x1, y1), (x2, y2))

    if d >= r1 + r2:  # two circle do not meet
        print("0.000")
    elif d + min(r1, r2) <= max(r1, r2):  # one circle is in the another one
        A = pi * (min(r1, r2) ** 2)
        print(f"{round(A, 3):.3f}")
    else:  # use second law of cosines
        theta1 = 2 * acos(((r1**2) + (d**2) - (r2**2)) / (2 * r1 * d))
        theta2 = 2 * acos(((r2**2) + (d**2) - (r1**2)) / (2 * r2 * d))
        A = ((r1**2) * (theta1 - sin(theta1)) / 2) + (
            (r2**2) * (theta2 - sin(theta2)) / 2
        )
        print(f"{round(A, 3):.3f}")
