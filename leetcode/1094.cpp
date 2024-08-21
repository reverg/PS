class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int passenger_diff[1001];
        fill(passenger_diff, passenger_diff + 1001, 0);

        for (vector<int> trip : trips)
        {
            int np = trip[0], from = trip[1], to = trip[2];
            passenger_diff[from] += np;
            passenger_diff[to] -= np;
        }

        int cur_passenger = 0;
        for (int i = 0; i <= 1000; i++)
        {
            cur_passenger += passenger_diff[i];
            if (cur_passenger > capacity)
                return false;
        }

        return true;
    }
};

/*
(Runtime, Memory) = (87.73%, 46.36%).
시간 O(max(N, 1001)), 공간 O(1001) 풀이. 0 <= from < to <= 1000이라
배열 크기가 최대 1001이고, 이 정도면 그냥 배열 다 만들어서 쓰는게 낫다.
위치 범위가 N보다 훨씬 커지면 배열의 크기가 너무 커져서 좋지 않은 방법이 된다.
이 경우엔 시간복잡도를 좀 희생해야 하는데, map을 사용해서  인원을 조작하거나
vector에 {from, np}와 {to, -np}를 넣고 sort하면 된다. 빠지는 사람이 타는 사람보다
먼저 고려되어야 하는데 sort하면 -np가 있는 to가 앞에 오므로 그냥 앞부터 쭉 더하면 된다.
이렇게 할 경우 시간복잡도는 O(NlogN), 공간은 O(N)이 된다. 어떤 풀이가 어떤 때 유리한지
잘 설명하면 좋을 듯. 확장성이 좋은건 후자라 follow-up 나오면 풀이를 바꿔야 될 것 같다.
*/