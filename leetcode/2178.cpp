class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        vector<long long> ans;
        if (finalSum % 2 != 0)
            return ans;

        // finalSum = (2 + 4 + ... + 2n) + r, r < 2n + 2
        // finalSum = (2 + 4 + ... 2(n-1)) + (2n + r)
        int num = 2;
        while (num <= finalSum)
        {
            finalSum -= num;
            ans.push_back(num);
            num += 2;
        }

        ans[ans.size() - 1] += finalSum;

        return ans;
    }
};

/*
(Runtime, Memory) = (66.94%, 32.86%).
unique한 숫자를 최대한 늘려야 하므로 greedy하게 작은 숫자부터 만든다.
최대한 만들고 남은 자투리는 마지막에 붙여버리면 앞의 숫자들과 겹칠 일이 없다.
최대 개수를 구하라고 하면 n(n+1) <= finalSum < (n+1)(n+2)가 되는 n을
sqrt로 O(1)에 구할 수 있겠지만 숫자를 모두 출력하는건 벡터에 넣는데만 O(N)이
걸리므로 부담없이 반복문으로 풀어도 된다. 시간 O(N), 공간 답 제외 O(1).
*/