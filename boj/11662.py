import sys, math

input = sys.stdin.readline


def ternarySearchTime(left, right):
    while abs(right - left) > 1e-9:
        left3 = (2 * left + right) / 3
        right3 = (left + 2 * right) / 3
        if dist_at(left3) > dist_at(right3):
            left = left3
        else:
            right = right3
    return dist_at(left)


def dist_at(t):
    my = Ay * t + By * (1 - t)
    mx = Ax * t + Bx * (1 - t)
    ky = cY * t + dY * (1 - t)
    kx = cX * t + dX * (1 - t)
    return math.dist((my, mx), (ky, kx))


if __name__ == "__main__":
    Ax, Ay, Bx, By, cX, cY, dX, dY = map(int, input().split())
    print("%.16f" % ternarySearchTime(0, 1))
