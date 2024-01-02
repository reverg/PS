N = int(input())
if N == 1:
    x, y = map(int, input().split())
    print(0)
else:
    min_x = 10001
    max_x = -10001
    min_y = 10001
    max_y = -10001
    for _ in range(N):
        x, y = map(int, input().split())
        if min_x > x:
            min_x = x
        if max_x < x:
            max_x = x
        if min_y > y:
            min_y = y
        if max_y < y:
            max_y = y

    print((max_x - min_x) * (max_y - min_y))
