/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p)
    {
        TreeNode *successor;

        while (root)
        {
            if (p->val >= root->val)
                root = root->right;
            else
            {
                successor = root;
                root = root->left;
            }
        }

        return successor;
    }
};

/*
(Runtime, Memory) = (78.76%, 19.09%)
우측 자식이 있으면 우로 하나 가고 좌로 쭉 내려가면 되는데, 그렇지 않으면
다음 수를 찾으러 위로 올라가야 한다. 그런데 노드에 부모 정보가 없으므로
직접 inorder로 순회를 해서 p 다음 수를 찾아야 한다. 최악의 경우는 극단적으로
치우쳐진(skewed) 트리이고, 이 경우에는 시간복잡도 O(N).

발상을 전환해서 root를 조작하면 좀 더 편하게 처리 가능하다. root를 조작한다는
말보다는 root에서 시작해서 탐색해간다는 말이 좀 더 정확할 것 같긴 하다.
root보다 p의 값이 크면 root가 커져야 하므로 root를 오른쪽으로 내린다.
root가 더 크면 p의 successor 후보 중 하나므로 일단 저장해두고, 왼쪽으로
내려서 더 작은 값을 가진 노드가 있나 확인한다. 트리를 벗어나는 경우엔
NULL이 되도록 잘 처리되어 있으므로 root가 NULL이 아닐 때까지 계속 움직이면서
확인해주면 된다. 이 방법도 시간복잡도가 O(N)이긴 하나 root를 직접 움직이면서
왼쪽 절반을 날려버리므로 constant가 좀 더 좋을 것이다.
*/