class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto inter : intervals)
        {
            if (!pq.empty() && pq.top() <= inter[0])
                pq.pop();

            pq.push(inter[1]);
        }

        return pq.size();
    }
};

/*
(Runtime, Memory) = (81.55%, 35.80%)
BOJ #1931과 꽤나 비슷한 문제. 그리디 알고리즘 문제이다.
회의실이 1개면 끝나는 시간 순으로 정렬하고 안 들어가는 회의는
모두 버려야 하지만 이 경우는 회의실을 늘려서 회의를 다 넣는
문제이므로 시작시간 순으로 정렬하고 빈 회의실을 체크해준다.
sort랑 pq 쓰므로 시간은 O(NlogN), 공간은 O(N)으로 된다.
*/