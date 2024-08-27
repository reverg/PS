class Solution
{
public:
    void recurseTree(TreeNode *node, int remainingSum, vector<int> &pathNodes,
                     vector<vector<int>> &pathsList)
    {
        if (node == NULL)
            return;

        pathNodes.push_back(node->val);

        if (node->left == NULL && node->right == NULL && remainingSum == node->val)
            pathsList.push_back(pathNodes);
        else
        {
            this->recurseTree(node->left, remainingSum - node->val, pathNodes, pathsList);
            this->recurseTree(node->right, remainingSum - node->val, pathNodes, pathsList);
        }

        pathNodes.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> pathsList;
        vector<int> pathNodes;
        this->recurseTree(root, sum, pathNodes, pathsList);
        return pathsList;
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
(Runtime, Memory) = (89.19%, 68.09%). #112 -> #113 -> #437 -> #666으로 이어진다.
경로를 가지고 DFS를 순회하다 리프까지 도달했을 때 합이 targetSum이면 정답 경로에 추가.
경로를 들고 올라오는 형식으로 하면 좀 느리다. 경로 순서가 반대여서 매번 가지고 있는 벡터를
O(N) 시간을 들여서 뒤에 붙여줘야하기 때문. 현재 코드의 경우 모든 노드를 한번씩 방문하고,
리프 노드에서 O(N) 배열을 답에 넣으므로 시간 O(N^2)에 풀린다. 공간은 tracking하는데 쓰는
pathNodes를 공유하므로 O(N). 다 따로 들고가면 O(N^2)이 되어버린다.

경로를 들고 올라오는 코드:
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;

        if(root == nullptr)
            return paths;

        if(root->left == nullptr && root->right == nullptr){
            if(root->val == targetSum)
                paths.push_back({root->val});
            return paths;
        }

        vector<vector<int>> left_paths = pathSum(root->left, targetSum - root->val);
        vector<vector<int>> right_paths = pathSum(root->right, targetSum - root->val);
        for(auto left_path: left_paths){
            vector<int> new_path = {root->val};
            new_path.insert(new_path.end(), left_path.begin(), left_path.end());
            paths.push_back(new_path);
        }
        for(auto right_path: right_paths){
                        vector<int> new_path = {root->val};
            new_path.insert(new_path.end(), right_path.begin(), right_path.end());
            paths.push_back(new_path);
        }

        return paths;
    }
};
*/