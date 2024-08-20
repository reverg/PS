class Solution
{
    int count = 0;
    int targetSum;
    unordered_map<long, int> sum_map;

    void preorder(TreeNode *node, long currSum)
    {
        if (node == nullptr)
            return;

        currSum += node->val;
        if (currSum == targetSum)
            count++;

        count += sum_map[currSum - targetSum];

        sum_map[currSum]++;
        preorder(node->left, currSum);
        preorder(node->right, currSum);
        sum_map[currSum]--;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        targetSum = sum;
        preorder(root, 0L);
        return count;
    }
};

/*
(Runtime, Memory) = (85.48%, 15.14%). #112 -> #113 -> #437 -> #66으로 이어진다.
root부터 쭉 이어진 경우에는 currSum이 targetSum과 같아지는 경우만 count를 늘려주면 된다.
문제는 root가 아니라 중간부터 이어져서 내려오는 경우이다. prefix sum의 아이디어를 이용해서
중간부터 이어진 경로는 (root부터 현재 경로의 끝점까지) - (root부터 현재 경로의 시작점까지)로
만들 수 있다. sum_map[currSum - targetSum]을 count에 더해주면 모든 중간에서 시작해서 현재
경로의 끝점까지 이어지는 것 중 합이 targetSum이 되는 경우를 카운팅하게 된다. currSum을 map에
넣고 빼는 것은 backtracking처럼 자식 탐색 전에 넣었다가 탐색 후에 빼주면 된다.
모든 노드를 1번씩 확인하므로 시간 O(N), 공간 O(N)에 풀린다.

모든 노드를 루트로 해서 합을 구하는 O(N^2) 풀이도 가능하긴 하다. 중복된 부분을 hash로 저장해서
시간복잡도를 내릴 수 있다는 발상을 하면 좋을 듯.
*/