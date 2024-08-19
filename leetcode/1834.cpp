class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<vector<int>> sorted_task;
        for (int i = 0; i < tasks.size(); i++)
            sorted_task.push_back({tasks[i][0], tasks[i][1], i});

        sort(sorted_task.begin(), sorted_task.end());

        vector<int> ans;
        long long cur_time = 0;
        int task_idx = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        while (task_idx < tasks.size() || !pq.empty())
        {
            if (pq.empty() && cur_time < sorted_task[task_idx][0])
                cur_time = sorted_task[task_idx][0];

            while (task_idx < sorted_task.size() && cur_time >= sorted_task[task_idx][0])
            {
                pq.push({sorted_task[task_idx][1], sorted_task[task_idx][2]});
                task_idx++;
            }

            auto [process_time, idx] = pq.top();
            pq.pop();

            cur_time += process_time;
            ans.push_back(idx);
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (68.54%, 26.96%).
현재 시각보다 enqueueTime이 빠른 것들 중 processingTime이 짧은 순, 그 다음은 인덱스가 빠른
순이라는 명확한 기준이 있어서 우선순위 큐를 쓰기 딱 좋은 문제다. 다만 현재 시각보다 enqueueTime이
빠르기만 하면 enqueueTime은 순위를 정하는데 배제된다는 것 때문에 우선순위 큐에 어떤 형태로 넣어야
할 지 고민이 좀 되는데, 따로 벡터를 만들어서 enqueueTime 순으로 정렬해뒀다가 현재 시각에 실행될 수
있는 모든 task들을 우선순위 큐에 넣어주는 방식으로 구현하면 해결된다. 우선순위 큐에서 pop했다가
시간을 바꿔서 다시 push하는 방식을 사용하면 최대 N번까지 다시 들어갈 수 있으므로 O(N^2 logN)이라는
좋지 않은 시간복잡도가 나올 것이다. 현재 코드에서는 sorting, pq 모두 O(NlogN)에 동작한다.
공간복잡도는 task들을 정렬한 벡터를 쓰므로 O(N).
*/