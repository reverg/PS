class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return validateBST(root, LONG_MIN, LONG_MAX);
    }

    bool validateBST(TreeNode *node, long long lo, long long hi)
    {
        if (node == NULL)
            return true;

        if (node->val < lo || node->val > hi)
            return false;

        return validateBST(node->left, lo, (long long)node->val - 1) &&
               validateBST(node->right, (long long)node->val + 1, hi);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
(Runtime, Memory) = (97.70%, 68.86%). 편차가 커서 의미는 없음.
CtCI에 나온 문제다.
단순히 부모 노드보다 크거나 작아야 되는게 아니라 더 위쪽 조상들에 대해서도 대소 관계가
성립해야 하므로 구간을 같이 들고가서 재귀적으로 확인해야 한다. 범위가 int인데 치사하게
node의 값이 int의 끝부터 끝까지라 node->val에 +-1을 할 때 overflow가 뜰 수 있음에
주의해야 한다. 복잡하게 값 나누기 싫어서 그냥 long long으로 캐스팅하는 꼼수를 사용했다.
DFS로 N개의 노드를 도니까 시간 O(N), 최대 N까지 depth가 늘어나므로 공간도 O(N)이다.
*/