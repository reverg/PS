class Solution
{
public:
    bool cross(int row, int col, int day, vector<vector<int>> &cells)
    {
        vector<vector<int>> board(row, vector<int>(col, 0));
        for (int i = 0; i < day; i++)
            board[cells[i][0] - 1][cells[i][1] - 1] = 1;

        queue<pair<int, int>> q;
        for (int i = 0; i < col; i++)
        {
            if (board[0][i] == 0)
            {
                q.push({0, i});
                board[0][i] = 2;
            }
        }

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {-1, 0, 1, 0};
        while (!q.empty())
        {
            auto [cr, cc] = q.front();
            q.pop();

            if (cr == row - 1)
                return true;

            for (int k = 0; k < 4; k++)
            {
                int nr = cr + dr[k];
                int nc = cc + dc[k];

                if (nc < 0 || nc >= col || nr < 0)
                    continue;

                if (board[nr][nc] == 0)
                {
                    q.push({nr, nc});
                    board[nr][nc] = 2;
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {

        int lo = 1;
        int hi = row * col;

        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            bool can_cross = cross(row, col, mid, cells);
            if (can_cross)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return lo - 1;
    }
};

/*
(Runtime, Memory) = (75.10%, 96.57%).
Parametric search를 하는 문제다. 시간이 지날수록 땅을 건너가기 힘들어지는 것을
잘 캐치하면 binary search로 정답 날짜를 좁힐 수 있음을 깨닫게 된다. 건널 수 있는지
확인은 매번 BFS로 해준다. 시간복잡도는 BFS에 O(RC), 이분탐색에 O(log(RC))이므로
총 O(RC log(RC)). 공간은 BFS때 쓰는 큐가 있어서 O(RC)다. union-find 풀이도 참고.
*/