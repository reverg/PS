import sys

input = sys.stdin.readline

MOD = 1000000007
N = 8
route = {}
D = int(input())


route[1] = [
    [0, 1, 0, 0, 0, 0, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 1],
    [0, 1, 0, 1, 0, 0, 1, 1],
    [0, 0, 1, 0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0, 1, 0, 0],
    [0, 0, 0, 0, 1, 0, 1, 0],
    [0, 0, 1, 1, 0, 1, 0, 1],
    [1, 1, 1, 0, 0, 0, 1, 0],
]


def travel(d, src, dst):
    if d <= 1:
        return route[d][src][dst]

    route.setdefault(d, [[0 for _ in range(N)] for _ in range(N)])
    if route[d][src][dst]:
        return route[d][src][dst]

    for mid in range(N):
        route[d][src][dst] += travel(d // 2, src, mid) * travel((d + 1) // 2, mid, dst)
        route[d][src][dst] %= MOD

    return route[d][src][dst]


print(travel(D, 0, 0))
