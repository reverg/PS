class Solution
{
public:
    int convertToMinutes(string &timePoint)
    {
        int hour = (timePoint[0] - '0') * 10 + (timePoint[1] - '0');
        int minute = (timePoint[3] - '0') * 10 + (timePoint[4] - '0');
        return hour * 60 + minute;
    }

    int findMinDifference(vector<string> &timePoints)
    {
        sort(timePoints.begin(), timePoints.end());

        int min_diff = 1440;
        for (int i = 0; i < timePoints.size() - 1; i++)
        {
            int min1 = convertToMinutes(timePoints[i]);
            int min2 = convertToMinutes(timePoints[i + 1]);

            int diff = min2 - min1;
            if (min_diff > diff)
                min_diff = diff;
        }
        min_diff = min(min_diff,
                       (convertToMinutes(timePoints[0]) + 1440) -
                           convertToMinutes(timePoints[timePoints.size() - 1]));

        return min_diff;
    }
};

/*
(Runtime, Memory) = (42.29%, 81.48%)
모든 시간을 비교해보면 O(N^2)이다. 당연히 바람직하지 않다.
의미가 있는건 앞뒤 시간과의 비교이므로 먼저 sort를 해주고 인접한
timePoint들에 대해 최소 시간 차이를 구해주면 된다. 마지막 비교때는
맨 앞 timePoint에 24시간을 더해 비교해주면 된다. substr, stoi 등을
적절히 잘 활용해줘도 되고, 시간을 미리 분으로 변환해두고 비교해도 좋다.
정렬이 들어가서 시간복잡도는 O(NlogN), 공간복잡도는 O(N)이 된다.
시간 비교 부분은 둘 다 O(N)이다.
*/