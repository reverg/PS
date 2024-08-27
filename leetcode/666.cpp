class Solution
{
public:
    int ans = 0;

    void dfs(int tree[16], int cur_node, int prev_sum)
    {
        int cur_sum = prev_sum + tree[cur_node];

        // last level or leaf node
        if ((cur_node * 2 >= 16) || (tree[cur_node * 2] == -1 && tree[cur_node * 2 + 1] == -1))
        {
            ans += cur_sum;
            return;
        }

        // check left child
        if (tree[cur_node * 2] != -1)
            dfs(tree, cur_node * 2, cur_sum);

        // check right child
        if (tree[cur_node * 2 + 1] != -1)
            dfs(tree, cur_node * 2 + 1, cur_sum);
    }

    int pathSum(vector<int> &nums)
    {
        int tree[16];
        fill(tree, tree + 16, -1);

        // generate tree
        for (int num : nums)
        {
            int d = num / 100;
            int p = (num / 10) % 10;
            int v = num % 10;
            tree[(1 << (d - 1)) + p - 1] = v;
        }

        dfs(tree, 1, 0);

        return ans;
    }
};
/*
(Runtime, Memory) = (100.00%, 88.24%). #112 -> #113 -> #437 -> #666으로 이어진다.
트리를 배열에 넣어버렸다. 앞의 2개를 따서 key로 써서 unordered_map에 넣고 left/right
child의 키를 만들아서 순회하는 방식도 사용 가능하고, treeNode 구현해도 된다.
그냥 오랜만에 배열에 넣어보고 싶었다. 확실하게 메모리 이점이 있긴 할텐데 리트코드 채점
상에서는 잘 드러나진 않는다. 트리 배열에 넣을 때 O(N), 순회할 때 모든 노드 1번씩 거쳐서
O(N)이므로 시간은 O(N). 공간도 배열 하나 쓰므로 O(N)이다.
*/