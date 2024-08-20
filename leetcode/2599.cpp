class Solution
{
public:
    int makePrefSumNonNegative(vector<int> &nums)
    {
        long long prefix_sum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            prefix_sum += nums[i];
            if (prefix_sum < 0)
            {
                prefix_sum -= pq.top();
                pq.pop();
            }
        }

        return nums.size() - pq.size();
    }
};

/*
(Runtime, Memory) = (53.33%, 23.33%).
앞부터 쭉 prefix_sum을 구하고, 만약 prefix_sum이 0보다 작아지면
지금까지 수들 중에 가장 작은 수를 맨 뒤로 보내면 된다. 양수의 합은
양수이므로 가장 작은 수는 음수인게 확정. 우선순위 큐를 사용해서
시간 O(NlogN), 공간 O(N)에 풀린다.
*/