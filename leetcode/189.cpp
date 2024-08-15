class Solution
{
public:
    void rotate_cyclic(vector<int> &nums, int k)
    {
        int size = nums.size();
        k = k % size;

        int start = 0, count = 0;
        while (count < size)
        {
            int current = start, prev = nums[start];
            do
            {
                int next = (current + k) % size;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                count++;
            } while (start != current);
            start++;
        }
    }

    void rotate_reverse(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    void reverse(vector<int> &nums, int start, int end)
    {
        while (start < end)
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};

/*
(Runtime, Memory): 실행마다 % 차이가 커서 의미가 없음
1. 제일 간단한 방법은 n번 돌리는 브루트포스. O(NK), O(1).
2. k개를 잠깐 빼두고 움직일 수 있다. O(N), O(K).
3. k씩 점프 뛰면서 바꿀 수도 있다(cyclic). O(N), O(1).
4. 일부분을 잘 뒤집어서 바꾸는 것도 가능(reverse). O(N), O(1).
하... 근데 솔직히 4번 풀이는 알고 있던거 아니면 어떻게 떠올림?
*/