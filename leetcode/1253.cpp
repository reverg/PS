class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower,
                                          vector<int> &colsum)
    {
        vector<vector<int>> ans;
        if (upper + lower != accumulate(colsum.begin(), colsum.end(), 0))
            return ans;

        vector<int> zero_vec(colsum.size(), 0);
        ans.push_back(zero_vec);
        ans.push_back(zero_vec);

        for (int i = 0; i < colsum.size(); i++)
        {
            if (colsum[i] == 2)
            {
                ans[0][i] = ans[1][i] = 1;
                upper--;
                lower--;
            }
        }

        for (int i = 0; i < colsum.size(); i++)
        {
            if (colsum[i] == 1)
            {
                if (upper)
                {
                    ans[0][i] = 1;
                    upper--;
                }
                else
                {
                    ans[1][i] = 1;
                    lower--;
                }
            }
        }

        if (upper != 0 || lower != 0)
            ans.clear();

        return ans;
    }
};

/*
(Runtime, Memory) = (75.10%, 96.57%).
시행착오를 좀 겪었다.
1. colsum 2를 다 반영하고 1을 반영해야 한다.
    그렇지 않으면 colsum이 1일 때 1을 어디에 배치할지결정하기가 힘들다.
2. upper, lower이 둘 다 0이 아닌지 체크해줘야 한다.
    8행만으로는 부족하다. colsum이 2인 경우를 lower/upper보다 크게 하면
    답을 구성할 수 없는데, 8행에선 그걸 반영하지 못한다.

코너 케이스를 잘 확인해줘야 하는 문제다. 매번 조심하자...
*/