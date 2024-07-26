#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Room
{
private:
    map<string, Room *> child;

public:
    void insert(vector<string> &foods, int index)
    {
        if (index == foods.size())
            return;

        if (child.find(foods[index]) == child.end())
            child[foods[index]] = new Room();

        child[foods[index]]->insert(foods, index + 1);
    }

    void output(int depth) // DFS
    {
        for (auto &ch : child)
        {
            for (int i = 0; i < depth; ++i)
                cout << "--";
            cout << ch.first << '\n';
            ch.second->output(depth + 1);
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int N, K;

    cin >> N;

    Room* root = new Room();
    for (int i = 0; i < N; i++)
    {
        cin >> K;
        vector<string> foods(K);
        for (int j = 0; j < K; j++)
        {
            cin >> foods[j];
        }
        root->insert(foods, 0);
    }
    root->output(0);
}