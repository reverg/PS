import sys

input = sys.stdin.readline


if __name__ == "__main__":
    N = int(input())
    house = [list(map(int, input().split())) for _ in range(N)]
    ans = 1000 * N

    for first_color in range(3):
        cost = [[1000 * N] * 3 for _ in range(N)]
        cost[0][first_color] = house[0][first_color]
        for i in range(1, N):
            cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + house[i][0]
            cost[i][1] = min(cost[i - 1][2], cost[i - 1][0]) + house[i][1]
            cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + house[i][2]

        for i in range(3):
            if first_color != i:
                ans = min(ans, cost[-1][i])

    print(ans)

"""
복잡해보일 수 있지만 원형인거에 크게 신경쓸 필요가 없다.
시작 색깔별로 dp를 3번 쓰고, dp가 끝날 때 시작이랑 끝 색이
같은지 확인해서 아닌 것만 취급한다. 굳이 따지면 3차원 dp.
"""
