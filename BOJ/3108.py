import sys


input = sys.stdin.readline


def find(r):
    if parents[r] != r:
        parents[r] = find(parents[r])
    return parents[r]


def union(r1, r2):
    p1 = find(r1)
    p2 = find(r2)
    parents[p2] = p1


def rectangles_meet(r1, r2):
    x1, y1, x2, y2 = rectangles[r1]
    x3, y3, x4, y4 = rectangles[r2]
    if x2 < x3 or x4 < x1 or y1 > y4 or y3 > y2:
        return False
    elif ((x1 < x3 <= x4 < x2) and (y1 < y3 <= y4 < y2)) or (
        (x3 < x1 <= x2 < x4) and (y3 < y1 <= y2 < y4)
    ):
        # = for (0, 0, 0, 0)
        return False
    else:
        return True


if __name__ == "__main__":
    N = int(input())
    rectangles = [[0, 0, 0, 0]] + [list(map(int, input().split())) for _ in range(N)]
    parents = list(range(N + 1))

    # put origin in rectangles and union
    for i in range(N):
        for j in range(i + 1, N + 1):
            if rectangles_meet(i, j):
                union(i, j)

    for i in range(N + 1):
        find(i)

    groups = set(parents)
    print(len(groups) - 1)
