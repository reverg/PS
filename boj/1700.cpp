#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    set<int> plugged;
    vector<int> plan(K);
    for (int i = 0; i < K; i++)
        cin >> plan[i];

    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        int cur = plan[i];

        if (plugged.find(cur) != plugged.end())
            continue;

        if (plugged.size() < N)
        {
            plugged.insert(cur);
            continue;
        }

        int latest_use_time = -1;
        auto unplug_target = plugged.begin();
        for (auto it = plugged.begin(); it != plugged.end(); it++)
        {
            int first_use_time = 0;
            int device = *it;
            bool will_be_used = false;

            for (int j = i + 1; j < K; j++)
            {
                if (plan[j] == device)
                {
                    will_be_used = true;
                    first_use_time = j;
                    break;
                }
            }

            if (!will_be_used)
                first_use_time = K;

            if (first_use_time > latest_use_time)
            {
                latest_use_time = first_use_time;
                unplug_target = it;
            }
        }

        plugged.erase(unplug_target);
        plugged.insert(cur);
        ans++;
    }

    cout << ans << '\n';
}
