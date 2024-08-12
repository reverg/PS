#include <iostream>
#include <vector>

using namespace std;

int N;
int board[10][10];
vector<int> bishops[19]; // /방향 좌표의 비숍들
bool diag2[19];          // \방향 배치 확인용
int max_bishops;

void dfs(int d1, int cnt)
{
    if (d1 == 2 * N - 1)
    {
        max_bishops = max(cnt, max_bishops);
        return;
    }

    bool placed = false;
    for (int d2 : bishops[d1])
    {
        if (diag2[d2])
            continue;

        placed = true;
        diag2[d2] = true;
        dfs(d1 + 1, cnt + 1);
        diag2[d2] = false;
    }

    if (!placed)
        dfs(d1 + 1, cnt);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < N; i++)
        {
            cin >> board[j][i];
            if (board[j][i] == 1)
                bishops[i + j].push_back(N - 1 + i - j);
        }
    }

    dfs(0, 0);

    cout << max_bishops << '\n';
}

/*
N-queen때는 같은 x좌표에 1개씩만 놓을 수 있으므로 가짓수가 많지 않았지만,
비숍은 대각선으로만 움직이므로 퀸 놓듯이 놓으면 너무 경우의 수가 많아진다.
체스판을 흑백으로 컬러링하고 backtracking을 따로 돌려서 시간복잡도를
O(2^100)에서 O(2^50 * 2)로 나누는 방법도 있지만(파이썬 풀이 참고) 이 코드에선
체스판을 대각선으로 돌려서 새로운 x, y 좌표를 만드는 방식으로 풀었다.
퀸을 놓을 때는 어찌됐건 x좌표마다 하나씩 퀸을 놓을 수 있지만 이번 경우에는
그렇지 않으므로 비숍을 놓는데 성공한 경우와 실패한 경우를 잘 나눠서 처리해줘야 한다.
실패했더라도 다음 줄로 넘어가줘야 끝까지 가서 모든 경우가 확인된다. 시간복잡도는 모든
흑백 칸을 확인하지 않고 비숍이 놓인 위치만 확인하게 되므로 O(2^비숍 높을 수 있는 칸 수)
정도로 떨어진다.
*/