import sys

sys.setrecursionlimit(100000)
input = sys.stdin.readline


def makeTree(cur, par):
    for node in connect[cur]:
        if node != par:
            children[cur].append(node)
            parent[node] = cur
            makeTree(node, cur)


def countSubTreeNodes(cur):
    size[cur] = 1
    for node in children[cur]:
        countSubTreeNodes(node)
        size[cur] += size[node]


if __name__ == "__main__":
    N, R, Q = map(int, input().split())
    connect = [[] for _ in range(N + 1)]
    for _ in range(N - 1):
        u, v = map(int, input().split())
        connect[u].append(v)
        connect[v].append(u)

    # construct tree
    children = [[] for _ in range(N + 1)]
    parent = [[] for _ in range(N + 1)]
    makeTree(R, -1)

    # count subtree nodes
    size = [[] for _ in range(N + 1)]
    countSubTreeNodes(R)

    # print answers
    for _ in range(Q):
        u = int(input())
        print(size[u])
