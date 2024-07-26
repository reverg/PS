#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
int ladder[31][11];

bool isJujak()
{
    // 1번 세로선부터 따라 내려가면서 확인: O(NH)
    for (int i = 1; i <= N; i++)
    {
        int tmp = i;
        for (int j = 1; j <= H; j++)
        {
            if (ladder[j][tmp])
                tmp++;
            else if (ladder[j][tmp - 1])
                tmp--;
        }

        if (tmp != i)
            return false;
    }

    return true;
}

bool backtrack(int cnt, int cy)
{
    if (cnt == 0)
        return isJujak();

    bool result = false;

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= H; j++)
        {
            if (ladder[j][i] || ladder[j][i - 1] || ladder[j][i + 1])
                continue;

            ladder[j][i] = 1;
            result = backtrack(cnt - 1, j);
            ladder[j][i] = 0;

            if (result == true)
                return true;

            // 세로줄 건너뛰어가면서 이동: 케이스 줄여줌
            while (j <= H && !ladder[j][i - 1] && !ladder[j][i + 1])
                j++;
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++)
    {
        int y, x;
        cin >> y >> x;
        ladder[y][x] = 1;
    }

    int ans = -1;
    for (int i = 0; i <= 3; i++)
    {
        if (backtrack(i, 1))
        {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
}

/*
조작 성공을 판별할 때 가로선들을 모두 벡터에 넣고 정렬한 뒤(세로->높이 순),
순회하면서 swap하고 i번째로 잘 갔는지 확인하는 방법도 가능. 문제 조건에서는
채점시엔 이 방법이 더 빠르긴 했지만 (320ms vs 488ms) O(MlogM)이라 가로선
개수가 (N-1)*H에 가까워지면 지금 풀이인 O(NH)보다 느릴 수 있음. 구현은
81203346번 제출 참고.
*/