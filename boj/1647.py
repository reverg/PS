import sys

input = sys.stdin.readline


def find(v):
    if parent[v] == v:
        return v

    parent[v] = find(parent[v])
    return parent[v]


def union(v1, v2):
    p1, p2 = find(v1), find(v2)
    if p1 > p2:
        parent[p1] = p2
    else:
        parent[p2] = p1


if __name__ == "__main__":
    N, M = map(int, input().split())
    parent = list(range(N + 1))
    roads = []
    for _ in range(M):
        src, dst, cost = map(int, input().split())
        roads.append((cost, src, dst))
    roads.sort(key=lambda x: x[0], reverse=True)

    cost_sum = 0
    last_edge_cost = 0
    while roads:
        cost, src, dst = roads.pop()
        if find(src) != find(dst):
            union(src, dst)
            cost_sum += cost
            last_edge_cost = cost

    print(cost_sum - last_edge_cost)
