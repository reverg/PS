class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        vector<int> count_task(26, 0);
        for (char task : tasks)
            count_task[task - 'A']++;

        int max_occur = *max_element(count_task.begin(), count_task.end());
        int max_count = 0;
        for (int occur : count_task)
            if (max_occur == occur)
                max_count++;

        int interval_if_idles_exist = (max_occur - 1) * (n + 1) + max_count;

        return max((int)tasks.size(), interval_if_idles_exist);
    }
};

/*
(Runtime, Memory) = (99.94%, 81.67%). #621 -> #2365로 이어진다.
중간에 idle한 cycle이 안 생기면 tasks의 크기가 최소 cycle이다. idle이 생기는
경우는 가장 많이 실행된 task들의 쿨타임 때문에 붕 뜨는 시간이 생기는 것인데,
max_occur과 max_count로 따로 센 다음 가장 많이 실행된 task들을 최대한 빨리
끝냈을 때 얼마나 시간이 걸리는지 확인해주면 된다. 둘 중 큰 것이 실행에 필요한 시간.
시간 O(N), 공간 O(K)인데 task 종류가 26개밖에 안돼서 O(K)=O(1)이다.

우선순위 큐를 사용한 풀이도 가능하다. pq에 {다음에 실행 가능한 시각, task 종류}를 넣고
가장 빨리 실행 가능한 것을 뽑아서 실행한 뒤, count_task 배열에 남은게 있으면 다음 실행
시각을 갱신해서 다시 pq에 넣어주는 것을 반복하면 된다. 시간 O(N logK), 공간 O(K)인데
K가 작은 상수라 O(N), O(1)에 풀린다. 만약 실행하는 task 배열을 찾으라고 하면 이게 좀
더 편하지 않을까 싶다.
*/