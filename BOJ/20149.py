import sys

input = sys.stdin.readline


def ccw(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)


def get_intersection(x1, y1, x2, y2, x3, y3, x4, y4):
    # y = ((y2-y1)/(x2-x1))(x-x1) + y1
    a1 = y2 - y1
    b1 = x1 - x2
    c1 = x1 * y2 - x2 * y1

    # y = ((y4-y3)/(x4-x3))(x-x3) + y3
    a2 = y4 - y3
    b2 = x3 - x4
    c2 = x3 * y4 - x4 * y3

    x = (b2 * c1 - b1 * c2) / (a1 * b2 - a2 * b1)
    y = (a2 * c1 - a1 * c2) / (a2 * b1 - a1 * b2)

    return x, y


def cross(l1, l2):
    x1, y1, x2, y2 = l1
    x3, y3, x4, y4 = l2

    mx1, my1 = min(x1, x2), min(y1, y2)
    mx2, my2 = max(x1, x2), max(y1, y2)
    mx3, my3 = min(x3, x4), min(y3, y4)
    mx4, my4 = max(x3, x4), max(y3, y4)

    ccw123 = ccw(x1, y1, x2, y2, x3, y3)
    ccw124 = ccw(x1, y1, x2, y2, x4, y4)
    ccw341 = ccw(x3, y3, x4, y4, x1, y1)
    ccw342 = ccw(x3, y3, x4, y4, x2, y2)

    if mx1 > mx4 or mx3 > mx2 or my1 > my4 or my3 > my2:
        print("0")
        return

    if ccw123 * ccw124 <= 0 and ccw341 * ccw342 <= 0:
        print("1")
        # gradient is same
        if (x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3):
            # meet at one point
            if mx1 == mx4 or mx2 == mx3:
                if [x1, y1] in [[x3, y3], [x4, y4]]:
                    print(x1, y1)
                elif [x2, y2] in [[x3, y3], [x4, y4]]:
                    print(x2, y2)
        else:
            print(*get_intersection(x1, y1, x2, y2, x3, y3, x4, y4))
    else:
        print(0)


if __name__ == "__main__":
    l1 = list(map(int, input().split()))
    l2 = list(map(int, input().split()))

    cross(l1, l2)
