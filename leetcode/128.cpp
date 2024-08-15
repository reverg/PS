class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> num_set(nums.begin(), nums.end());
        int longestStreak = 0;
        for (int num : nums)
        {
            if (!num_set.count(num))
                continue;

            int streak = 1;
            num_set.erase(num);

            int num_small = num - 1;
            while (num_set.count(num_small))
            {
                num_set.erase(num_small);
                streak++;
                num_small--;
            }

            int num_big = num + 1;
            while (num_set.count(num_big))
            {
                num_set.erase(num_big);
                streak++;
                num_big++;
            }

            longestStreak = max(streak, longestStreak);
        }

        return longestStreak;
    }
};

/*
(Runtime, Memory) = (72.78%, 43.20%)
누군가 시간복잡도를 묻거든... 고개를 들어 해시를 보게 하라...

정렬해서 streak 찾으면 O(NlogN) / C++ 기준 O(logN).
hash에 다 때려박으면 O(N) / O(N)에 풀린다. 중간에 방문한 값들
set에서 안 지워주면 나중에 또 세져서 O(N^2) 될 수 있음에 유의.
물론 delete mark 남아서 다음 검색에 O(N)이 들어버릴 수도 있지만
STL이 쓰는 해쉬 함수를 들고 와서 저격할 거 아니면 안 걸릴 듯.

Union-find 풀이도 존재한다. unordered_map에 (nums[i], i) 형태로
다 넣고 nums를 다시 돌면서 nums[i]-1을 map에서 찾아 있으면 union.
union때 size를 같이 기록해뒀다가 나중에 nums를 다시 돌면서 가장
큰 union의 크기를 return하면 된다. 잘 구현하면 union, find가
O(1)에 근접해서 이론적으로 O(N)인걸로 알긴 하는데 구현 난이도를
생각하면 그냥 unordered_set 쓰는게 나을 듯.
*/