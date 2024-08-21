class Solution
{
public:
    int waysToPartition(vector<int> &nums, int k)
    {
        long long sum = 0;
        for (int num : nums)
            sum += num;

        unordered_map<long, int> after_pivot_diff;
        unordered_map<long, int> before_pivot_diff;

        long long left_sum = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            left_sum += nums[i];
            long long right_sum = sum - left_sum;
            after_pivot_diff[left_sum - right_sum]++;
        }

        int max_pivot_num = after_pivot_diff[0]; // didn't change num to k
        left_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            left_sum += nums[i];
            long long right_sum = sum - left_sum;

            int cur_pivot_num = before_pivot_diff[k - nums[i]] + after_pivot_diff[-(k - nums[i])];
            if (max_pivot_num < cur_pivot_num)
                max_pivot_num = cur_pivot_num;

            after_pivot_diff[left_sum - right_sum]--;
            before_pivot_diff[left_sum - right_sum]++;
        }

        return max_pivot_num;
    }
};

/*
(Runtime, Memory) = (78.29%, 64.87%).
Hash map을 아주 잘 사용해야 하는 문제다. nums[i]를 바꾸고 pivot의 개수를 세는 것이 작업인데,
nums[i]를 바꾸는건 무조건 O(N)이므로 pivot의 개수를 빠르게 세는 것이 핵심이다. 모든 위치마다
전체 합 - 왼쪽 합을 구하면 pivot 개수를 세는데 O(N)이 걸리므로 전체 시간은 O(N^2)이 된다.

Hash map을 잘 사용하면 O(1)에 확인이 가능하다. 먼저 left_sum - right_sum을 map에 다 카운팅한다.
nums를 바꾸지 않았을 경우엔 map의 key가 0인 경우가 답이다. 이제 nums[i]를 바꾸면 어떻게 되는지
생각해보자. 바꾼 nums[i]가 pivot의 왼쪽이면 left_sum이 k 증가하고, 오른쪽이면 right_sum이 k 증가한다.
전자는 left_sum - right_sum이 k, 후자는 -k가 된다. 이제 pivot의 위치가 왼쪽인지 오른쪽인지를 어떻게
구별할 것인지가 문제이다. Hash map을 하나 더 만들어서 이번 left_sum - right_sum의 수를 하나 늘려주면
pivot 왼쪽 수들이 카운팅된다. pivot이 오른쪽으로 갔으니 원래 쓰던 map에서는 수를 하나 줄여야한다. 이제
처음부터 끝까지 순회하면서 pivot 수를 확인하고 최대 pivot 수를 저장해두면 된다.

처음 만든 map은 after_pivot_diff, 다음에 만든건 before_pivot_diff다. 각각 pivot이 바꾼 수의 오른쪽/왼쪽에
있을 경우의 가짓수이다. map 확인과 수정 작업이 모두 O(1)이므로 pivot 개수 세는게 O(1)이 되어 최종적으로 O(N)
시간이 걸린다. 공간은 같은 크기의 map을 썼으므로 O(N).
*/