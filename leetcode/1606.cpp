class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        int n = arrival.size();
        vector<int> serverLoad(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busyServers;
        set<int> freeServers;

        for (int i = 0; i < k; i++)
            freeServers.insert(i);

        for (int i = 0; i < n; i++)
        {
            int ct = arrival[i];
            while (!busyServers.empty() && busyServers.top().first <= ct)
            {
                freeServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            if (freeServers.empty())
                continue;

            auto it = freeServers.lower_bound(i % k);
            if (it == freeServers.end())
                it = freeServers.begin();
            int targetServer = *it;

            freeServers.erase(it);
            serverLoad[targetServer]++;
            busyServers.emplace(ct + load[i], targetServer);
        }

        vector<int> ans;
        int maxLoad = *max_element(serverLoad.begin(), serverLoad.end());
        for (int i = 0; i < k; i++)
            if (serverLoad[i] == maxLoad)
                ans.push_back(i);

        return ans;
    }
};

/*
(Runtime, Memory) = (87.70%, 62.70%)
작업 중인 서버는 priority queue, 빈 서버는 set으로 관리한다.
새로운 작업을 할당할 때마다 priority queue를 확인해 작업이 끝난
서버들은 모두 제거하고 set에 삽입한다. 새로운 서버 할당은 set에서
lower_bound로 구한다. 직접 i%k번부터 순회하면 최악의 경우 O(K)이고
총 시간복잡도가 O(NK)여서 느리다. 이분탐색으로 구하면 O(NlogK)로
처리 가능하다.
*/