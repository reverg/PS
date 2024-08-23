class Solution
{
public:
    int find_land(vector<int> &parent, int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find_land(parent, parent[x]);
    }

    bool union_land(vector<int> &parent, int u, int v)
    {
        u = find_land(parent, u);
        v = find_land(parent, v);

        if (u == v)
            return false;
        else
        {
            parent[u] = v;
            return true;
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        vector<vector<int>> board(row, vector<int>(col, 1));
        vector<int> parent(row * col + 2); // top = row*col, bottom = row*col + 1
        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};

        for (int day = cells.size() - 1; day >= 0; day--)
        {
            int cr = cells[day][0] - 1;
            int cc = cells[day][1] - 1;
            int cidx = cr * col + cc;
            board[cr][cc] = 0;

            for (int k = 0; k < 4; k++)
            {
                int nr = cr + dr[k];
                int nc = cc + dc[k];
                int nidx = nr * col + nc;

                if (nr < 0 || nr >= row || nc < 0 || nc >= col)
                    continue;

                if (board[nr][nc] == 0)
                    union_land(parent, cidx, nidx);

                if (cr == 0)
                    union_land(parent, cidx, row * col);
                if (cr == row - 1)
                    union_land(parent, cidx, row * col + 1);

                if (find_land(parent, row * col) ==
                    find_land(parent, row * col + 1))
                    return day;
            }
        }
        return -1;
    }
};

/*
(Runtime, Memory) = (93.31%, 95.60%).
마지막에 모든 땅이 물이 된 시점부터 거꾸로 1칸씩 돌아가면서 최초로 위에서 아래로 건너갈 수 있는
날을 찾는다. 새로 추가된 땅을 주변의 땅과 union해서 땅을 넓혀가다가, 맨 윗줄과 맨 아랫줄의 땅이
연결되면 구역을 건널 수 있다. 맨 윗 줄과 맨 아랫 줄은 칸별로 모두 parent를 따로 두면 확인하는데
O(N) 시간이 걸리는데, 맨 윗 줄과 아랫 줄을 묶는 top, bottom 노드를 추가로 둬서 연결시키면 확인을
O(1)으로 줄일 수 있다. BOJ #1368 같은 느낌. union-find가 평균적으로 O(1)에 동작하므로 시간복잡도는
O(RC), 공간복잡도도 O(RC)다.
*/