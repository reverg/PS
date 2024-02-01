import sys

input = sys.stdin.readline


def find_min_dist(start, end):
    # base conditions
    if end - start == 1:
        return sys.maxsize
    if end - start == 2:
        return (points[start][0] - points[end - 1][0]) ** 2 + (
            points[start][1] - points[end - 1][1]
        ) ** 2

    # divide and conquer
    mid = (start + end) // 2
    left = find_min_dist(start, mid)
    right = find_min_dist(mid, end)
    min_dist = min(left, right)

    # check points around mid
    check_point = []
    for i in range(start, end):
        # if x diff > min_dist: no need to check
        if (points[i][0] - points[mid][0]) ** 2 <= min_dist:
            check_point.append(points[i])
    check_point.sort(key=lambda x: x[1])

    for i in range(len(check_point)):
        p1 = check_point[i]
        for j in range(i + 1, len(check_point)):
            p2 = check_point[j]
            # if y diff > min_dist: no need to check
            if (p2[1] - p1[1]) ** 2 >= min_dist:
                break
            dist = (p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2
            min_dist = min(min_dist, dist)

    return min_dist


if __name__ == "__main__":
    n = int(input())
    points = [list(map(int, input().split())) for _ in range(n)]
    points.sort()

    print(find_min_dist(0, n))
