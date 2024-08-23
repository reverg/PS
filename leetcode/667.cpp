class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans(n);

        int c = 0;
        for (int v = 1; v < n - k; v++)
            ans[c++] = v;
        for (int i = 0; i <= k; i++)
            ans[c++] = (i % 2 == 0) ? ((n - k) + (i / 2)) : ((n - k) + (k - i / 2));

        return ans;
    }
};

/*
(Runtime, Memory) = (100.00%, 79.27%). #526 -> #667인데 그닥 연관성이 없다.
조건에 맞는 수열을 직접 만들어버리면 된다. 첫 번째부터 n-k-1번째까지는 1 차이,
n-k번째부터 n번째까지는 k, k-1, ..., 2 차이가 난다. 직접 만드므로 시간 O(N),
공간 답 제외 O(1) 풀이. 근데 이걸 어떻게 생각함...?
*/