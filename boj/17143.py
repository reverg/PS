import sys

input = sys.stdin.readline


def fish(t):
    size = 0
    for j in range(R):
        if pool[j][t]:
            size = pool[j][t][2]
            pool[j][t] = 0
            break
    return size


def get_next_loc(j, i, speed, dir):
    if dir == 1 or dir == 2:
        cycle = 2 * (R - 1)
        if dir == 1:
            cur = speed + cycle - j
        else:
            cur = speed + j
        cur %= cycle
        if cur >= R:
            return (cycle - cur, i, 1)
        else:
            return (cur, i, 2)
    else:
        cycle = 2 * (C - 1)
        if dir == 4:
            cur = speed + cycle - i
        else:
            cur = speed + i
        cur %= cycle
        if cur >= C:
            return (j, cycle - cur, 4)
        else:
            return (j, cur, 3)


def shark_move():
    global pool
    new_pool = [[0 for _ in range(C)] for _ in range(R)]

    for j in range(R):
        for i in range(C):
            if pool[j][i]:
                shark = pool[j][i]
                ny, nx, nd = get_next_loc(j, i, shark[0], shark[1])
                if new_pool[ny][nx]:
                    new_pool[ny][nx] = max(
                        new_pool[ny][nx], (shark[0], nd, shark[2]), key=lambda x: x[2]
                    )
                else:
                    new_pool[ny][nx] = (shark[0], nd, shark[2])

    pool = new_pool


if __name__ == "__main__":
    R, C, M = map(int, input().split())
    sharks = []
    pool = [[0 for _ in range(C)] for _ in range(R)]
    for i in range(M):
        r, c, s, d, z = map(int, input().split())
        pool[r - 1][c - 1] = (s, d, z)

    size_sum = 0
    for t in range(C):
        size_sum += fish(t)
        shark_move()

    print(size_sum)
