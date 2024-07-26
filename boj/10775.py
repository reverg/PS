import sys

input = sys.stdin.readline


def find(v):
    if parents[v] == v:
        return v
    parents[v] = find(parents[v])
    return parents[v]


def union(v1, v2):
    p1, p2 = find(v1), find(v2)
    if p1 < p2:
        parents[p2] = p1
    else:
        parents[p1] = p2


if __name__ == "__main__":
    G = int(input())
    P = int(input())
    parents = [i for i in range(G + 1)]  # for gates

    cnt = 0
    for _ in range(P):
        g = int(input())
        trg_gate = find(g)
        if trg_gate != 0:
            cnt += 1
            # each parents shows available gate
            union(trg_gate, find(trg_gate - 1))
        else:
            break

    print(cnt)
