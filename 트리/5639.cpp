#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

void postorder(int start, int end)
{
    if (start >= end)
        return;

    int mid;
    for (mid = start + 1; mid < end; mid++)
    {
        if (tree[start] < tree[mid])
            break;
    }

    postorder(start + 1, mid);
    postorder(mid, end);
    cout << tree[start] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int input;
    while (cin >> input)
        tree.emplace_back(input);

    postorder(0, tree.size());
}