class Solution
{
public:
    int sumImbalanceNumbers(vector<int> &nums)
    {
        int ans = 0;
        int n = nums.size();

        vector<int> left(n);
        vector<int> pos_of_value(n + 2, -1);
        for (int i = 0; i < n; i++)
        {
            left[i] = max(pos_of_value[nums[i] + 1], pos_of_value[nums[i]]);
            pos_of_value[nums[i]] = i;
        }

        vector<int> right(n);
        fill(pos_of_value.begin(), pos_of_value.end(), n);
        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = pos_of_value[nums[i] + 1];
            pos_of_value[nums[i]] = i;
        }

        for (int i = 0; i < n; i++)
            ans += (i - left[i]) * (right[i] - i);
        ans -= n * (n + 1) / 2;

        return ans;
    }
};

/*
(Runtime, Memory) = (96.47%, 87.65%).
brute force로 모든 subarray를 확인해보는 풀이는 O(N^3). 
set에다 nums[i]~nums[j]를 넣고 새로운 수를 추가할 때마다 기존 set에 +-로 차이나는게 있나 확인해서
현재 imbalance number를 조정해주면 O(N^2)으로 낮출 수 있다. 아래 코드 참고.
    cur += s.count(A[j]) ? 0 : 1 - s.count(A[j] + 1) - s.count(A[j] - 1);
    
subarray를 만들어서 세는게 아니라 각각의 원소가 몇 개의 subarray에서 imbalance로 count될 수 있는지
세면 O(N) 풀이가 가능하다. x에 대해 x+1이 아닌 x보다 큰 수가 있는 경우의 수를 세보자. x+1이 있으면
그 subarray에선 카운트 되지 않으므로 왼쪽과 오른쪽으로 x+1이 나오기 전까지 얼마나갈 수 있는지를 세자(9~23행).
그 후에 왼쪽으로 간 거리와 오른쪽으로 간 거리를 곱하면 x가 포함된 조합의 개수가 나오므로 답에 더해주면(25~26행)
되...지 않는다. 자신과 같은 원소가 나온 경우에는 카운트 해주면 안되고, x가 해당 subarray에서 가장 큰 원소여서
imbalance로 카운트되지 않는 경우도 빼줘야 한다. 전자는 왼쪽으로 갈 때 x+1이나 x가 나오면 멈추는 방식으로 중복되지
않게 구간을 잡아주면 해결되고, 후자는 가능한 subarray 개수인 N(N-1)/2개를 빼주면 된다(27행). 결과적으로 시간, 공간
모두 O(N)에 풀이가 가능하다.

솔직히 면접 때 이런 풀이를 떠올리긴 힘들거고, 일단 subarray를 모두 구하는 방식은 O(N^2)보다 빠르게 풀 수 없음을
잘 확인해서 O(N^2) 풀이를 제시하고 힌트를 받아야 될 것 같다. 방법이 얼추 떠올라도 중복 제거 때문에 머리가 아플텐데
어차피 제대로 푸는 사람은 괴수밖에 없을테니 괜찮을지도...
*/