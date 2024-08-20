class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(processorTime.begin(), processorTime.end(), greater<>());
        sort(tasks.begin(), tasks.end());

        int complete_time = 0;
        for (int i = 0; i < processorTime.size(); i++)
        {
            int max_time_task = *max_element(tasks.begin() + 4 * i, tasks.begin() + 4 * i + 4);
            if (processorTime[i] + max_time_task > complete_time)
                complete_time = processorTime[i] + max_time_task;
        }

        return complete_time;
    }
};

/*
(Runtime, Memory) = (89.66%, 46.91%).
Greedy하게 일찍 사용 가능한 프로세서에 시간이 오래 걸리는 task를 배치해주면 된다.
*/