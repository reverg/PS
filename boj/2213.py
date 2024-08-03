import sys

sys.setrecursionlimit(100000)
input = sys.stdin.readline


def dfs(cur):
    dp[cur][1] += weight[cur]
    node_set[cur][1].append(cur)

    for node in tree[cur]:
        if not visited[node]:
            visited[node] = True
            sub_node_set = dfs(node)
            dp[cur][0] += max(dp[node][0], dp[node][1])
            dp[cur][1] += dp[node][0]
            node_set[cur][0] += (
                sub_node_set[0] if dp[node][0] > dp[node][1] else sub_node_set[1]
            )
            node_set[cur][1] += sub_node_set[0]

    return node_set[cur]


if __name__ == "__main__":
    N = int(input())
    tree = [[] for _ in range(N + 1)]
    weight = [0] + list(map(int, input().split()))
    for _ in range(N - 1):
        u, v = map(int, input().split())
        tree[u].append(v)
        tree[v].append(u)

    dp = [[0, 0] for _ in range(N + 1)]
    node_set = [[[] for _ in range(2)] for _ in range(N + 1)]
    visited = [False] * (N + 1)
    visited[1] = True

    p = dfs(1)

    max_weight_sum, max_weight_path = (
        (dp[1][0], p[0]) if dp[1][0] > dp[1][1] else (dp[1][1], p[1])
    )
    max_weight_path.sort()

    print(max_weight_sum)
    for node in max_weight_path:
        print(node, end=" ")

"""
#1949에 경로 추적이 추가된 문제.
node_set[i][j]: i번째 노드를 선택X/선택했을 때 포함되는 독립집합 원소들
i번째 노드를 포함하지 않을거면 자식을 넣는게 큰지 빼는게 큰지 확인하고,
해당하는 path를 추가한다. 포함할거면 자식은 다 포함할 수 없으므로
sub_node_set[0]을 추가한다. 헷갈리면 visited 배열을 두고 dp[node][0]과
dp[node][1]을 비교해서 dp[node][1]이 더 크면 추가하는 방식으로 dfs를 1번
더 돌아서 배열을 만드는 것도 좋다.
"""
