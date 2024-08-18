class Solution
{
public:
    long long taskSchedulerII(vector<int> &tasks, int space)
    {
        unordered_map<int, long long> break_schedule;

        long long time = 1;
        for (int task : tasks)
        {
            if (time < break_schedule[task])
                time = break_schedule[task];

            break_schedule[task] = time + (space + 1);
            time++;
        }

        return time - 1;
    }
};

/*
(Runtime, Memory) = (85.23%, 62.25%). #621 -> #2365로 이어진다.
#621와 이어져 있긴 하지만 그닥 연관성은 없다. task의 종류가 아주 많아서 unordered_map을
vector 대신 사용해줘야 한다. 또한 순서대로 실행되므로 이전에 실행된 동일한 task의 쿨타임까지
기다렸다가 새로운 작업을 실행하는 과정을 반복해줘야 한다. 그냥 hash table을 갱신하면서 시간을
늘려주면 되는 간단한 문제.
*/