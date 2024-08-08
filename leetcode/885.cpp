class Solution
{
public:
    int dy[4] = {0, 1, 0, -1};
    int dx[4] = {1, 0, -1, 0};

    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart,
                                        int cStart)
    {
        vector<vector<int>> ans;

        int step = 1;
        int cur_r = rStart;
        int cur_c = cStart;
        ans.push_back({rStart, cStart});

        int cnt = 1;
        int dir = 0; // (r, d, l, u) = (0, 1, 2, 3)
        while (true)
        {
            for (int i = 0; i < step; i++)
            {
                cur_r += dy[dir];
                cur_c += dx[dir];

                if ((0 <= cur_r && cur_r < rows) &&
                    (0 <= cur_c && cur_c < cols))
                {
                    cnt++;
                    ans.push_back({cur_r, cur_c});
                }
            }

            if (dir % 2 == 1)
                step++;

            dir = (dir + 1) % 4;

            if (cnt == rows * cols)
                break;
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (91.69%, 23.17%)
칼같이 배열 안쪽만 돌게 만드려면 내가 먼저 돌아버릴 것
같아서 그냥 좀 넉넉하게 밖까지 돌게 만들었다.
평범하게 정해진 크기대로 다 돌되 배열 내부 인덱스일 때만
정답에 넣게 했다. 배열 크기와 넣은 개수가 같아지면 종료.
O(max(M,N)^2)인데 변 길이가 100이 될 때까지 돌아봤자 1만이라
시간에 큰 영향은 없다. 그냥 구현 편한게 이득이라 생각됨.
*/