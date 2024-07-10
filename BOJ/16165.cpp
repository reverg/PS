#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    unordered_map<string, vector<string>> groups;
    unordered_map<string, string> member;

    for (int i = 0; i < N; i++)
    {
        int num;
        string group;
        cin >> group >> num;

        vector<string> members;
        for (int j = 0; j < num; j++)
        {
            string name;
            cin >> name;
            members.push_back(name);
            member.insert({name, group});
        }
        sort(members.begin(), members.end());
        groups.insert({group, members});
    }

    for (int i = 0; i < M; i++)
    {
        string p;
        int question;

        cin >> p >> question;
        if (question == 1)
        {
            cout << member[p] << '\n';
        }
        else
        {
            for (auto it : groups[p])
                cout << it << '\n';
        }
    }
}