class Solution
{
public:
    map<int, int> painted_intervals;

    int insertInterval(int start, int end)
    {
        auto up_it = painted_intervals.upper_bound(end);
        auto lo_it = prev(painted_intervals.lower_bound(start));
        if (lo_it->second < start)
            lo_it++;

        int new_paint = end - start;
        for (auto it = lo_it; it != up_it; it++)
        {
            new_paint -= min(end, it->second) - max(start, it->first);
            start = min(start, it->first);
            end = max(end, it->second);
        }

        painted_intervals.erase(lo_it, up_it);
        painted_intervals[start] = end;

        return new_paint;
    }

    vector<int> amountPainted(vector<vector<int>> &paint)
    {
        vector<int> ans;

        painted_intervals[-1] = -1;
        painted_intervals[50001] = 50001;
        for (auto p : paint)
            ans.push_back(insertInterval(p[0], p[1]));

        return ans;
    }
};

/*
(Runtime, Memory) = (56.34%, 34.27%)
유니온 파인드를 써서 시작점과 끝점을 바로 알아낼 수 있지 않을까?
라고 생각을 했었는데, 결국 구간 내 모든 점들의 parent(여기서는
left/right)를 다 바꿔줘야 해서 효율이 떨어진다.
색칠된 구간들을 map에 넣고 이분탐색으로 목표 구간 가장 근처의 구간
정보를 가져와서 빈 부분을 색칠했다. 시간복잡도는 O(NlogN).
start와 end를 매번 구할 필요는 없으니 다소 최적화될 여지가 있지만...
머리가 아파서 일단 포기. 그렇게 유의미한 차이는 없을 것 같다.
*/