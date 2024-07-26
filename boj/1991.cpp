#include <iostream>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> graph[27];

void preorder(int root_int)
{
    if (root_int == 0)
        return;

    cout << (char)('A' + root_int - 1);
    preorder(graph[root_int][0].first);
    preorder(graph[root_int][0].second);
}

void inorder(int root_int)
{
    if (root_int == 0)
        return;

    inorder(graph[root_int][0].first);
    cout << (char)('A' + root_int - 1);
    inorder(graph[root_int][0].second);
}


void postorder(int root_int)
{
    if (root_int == 0)
        return;

    postorder(graph[root_int][0].first);
    postorder(graph[root_int][0].second);
    cout << (char)('A' + root_int - 1);
}


int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin >> N;

    char root, pred[2];
    for (int i = 1; i <= N; i++)
    {
        cin >> root >> pred[0] >> pred[1];
        int root_int, pred_int[2];
        root_int = root - 'A' + 1;
        for (int i = 0; i < 2; i++)
        {
            if (pred[i] == '.')
                pred_int[i] = 0;
            else
                pred_int[i] = pred[i] - 'A' + 1;
        }
        graph[root_int].emplace_back(make_pair(pred_int[0], pred_int[1]));
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);
}