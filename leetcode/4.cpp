class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;

        while (left <= right)
        {
            int partitionA = (left + right) / 2;
            int partitionB = (m + n + 1) / 2 - partitionA;

            int maxLeftA = (partitionA == 0) ? INT_MIN : nums1[partitionA - 1];
            int minRightA = (partitionA == m) ? INT_MAX : nums1[partitionA];
            int maxLeftB = (partitionB == 0) ? INT_MIN : nums2[partitionB - 1];
            int minRightB = (partitionB == n) ? INT_MAX : nums2[partitionB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                if ((m + n) % 2 == 0)
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                else
                    return max(maxLeftA, maxLeftB);
            }
            else if (maxLeftA > minRightB)
                right = partitionA - 1;
            else
                left = partitionA + 1;
        }

        return 0.0;
    }
};

/*
(Runtime, Memory) = (71.03%, 60.38%).
2개의 벡터를 합친 후에 sort해서 중간을 찾으면 O((N+M) log(N+M)).

투 포인터로 맨 앞부터 1개씩 넘어가면서 찾으면 O(N+M).

이분 탐색을 쓰면 O(log(min(M, N)))에 가능하다.
nums1의 인덱스가 정해지면 nums2의 인덱스는 (N+M의 절반 - nums1 인덱스)로
고정됨을 이용해서 nums1의 인덱스를 기준으로 이분탐색하면 된다.
중앙값인지 확인하는 부분(24~34행)이 O(1)이므로 전체는 O(logN). nums1과 nums2
중에서 크기가 작은 거에서 탐색하면 되므로 O(log(min(M, N)))까지 떨어뜨릴 수 있다.
처음에는 nums1에서 인덱스 결정 -> nums2에서 해당 값보다 작은 수 lower_bound로 카운트
-> nums1에서 범위 변경 순으로 진행되는 O(logN logM) 풀이를 생각했었는데, nums1에서
깔끔하게 중앙값이 안 나오면 nums2에서 같은 과정을 반복해야 하는 문제가 있었다.
nums1의 인덱스가 정해지면 nums2의 중앙값이 있어야 되는 위치가 정해진다는 것을 잘 활용하자.
*/