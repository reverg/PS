#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
string name[1001];
unordered_map<string, int> id;
vector<int> adj[1001];
int indeg[1001] = {0};
vector<int> ancestors;
vector<int> tr[1001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // string 처리하기 힘드니까 id 부여
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> name[i];
    sort(name + 1, name + N + 1);
    for (int i = 1; i <= N; i++)
        id[name[i]] = i;

    // 위상정렬 위한 graph 정보 입력
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        adj[id[s2]].push_back(id[s1]);
        indeg[id[s1]]++;
    }

    // 부모 없으면 조상
    for (int i = 1; i <= N; i++)
    {
        if (indeg[i] == 0)
            ancestors.push_back(i);
    }

    // 조상 수를 보고 자식 판별
    // 연결된 사람의 조상 수가 자기보다 1 작으면 자식
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end()); // 이후에 사전순 출력
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (indeg[adj[i][j]] == indeg[i] + 1)
                tr[i].push_back(adj[i][j]);
        }
    }

    // 가문 수, 시조 이름 출력
    cout << ancestors.size() << '\n';
    for (int i = 0; i < ancestors.size() - 1; i++)
        cout << name[ancestors[i]] << ' ';
    cout << name[ancestors[ancestors.size() - 1]] << '\n';

    // 이름 사전순으로 자식 정보 출력
    for (int i = 1; i <= N; i++)
    {
        cout << name[i] << ' ' << tr[i].size();
        for (int j = 0; j < tr[i].size(); j++)
            cout << ' ' << name[tr[i][j]];
        cout << '\n';
    }
}

/*
위상 정렬과 상당히 비슷하지만 정렬하지는 않고,
indegree 수를 세는 아이디어를 빌려와 사용한다.
sort 부분이 O(NlogN), 자식 판별이 O(N+2M).
합치면 O(NlogN+M) 정도로 처리된다.
*/