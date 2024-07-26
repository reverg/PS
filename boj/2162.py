import sys

input = sys.stdin.readline


def find(v):
    if v == parent[v]:
        return v
    else:
        parent[v] = find(parent[v])
    return parent[v]


def union(v1, v2):
    p1, p2 = find(v1), find(v2)
    if p1 < p2:
        parent[p2] = p1
    else:
        parent[p1] = p2


def ccw(x1, y1, x2, y2, x3, y3):
    return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)


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

    # two lines are on the one straight line
    if ccw123 * ccw124 == 0 and ccw341 * ccw342 == 0:
        # check vertex locations
        if mx1 <= mx4 and mx3 <= mx2 and my1 <= my4 and my3 <= my2:
            return True
    else:
        # three points are on the same line
        if ccw123 * ccw124 <= 0 and ccw341 * ccw342 <= 0:
            return True

    return False


if __name__ == "__main__":
    N = int(input())
    lines = [list(map(int, input().split())) for _ in range(N)]
    parent = [i for i in range(N)]

    for i in range(N - 1):
        for j in range(i + 1, N):
            if cross(lines[i], lines[j]):
                union(i, j)

    group_num = 0
    group_line_cnt = [0] * N

    for i in range(N):
        if parent[i] == i:
            group_num += 1
        group_line_cnt[find(i)] += 1

    print(group_num)
    print(max(group_line_cnt))
