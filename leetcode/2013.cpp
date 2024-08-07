class DetectSquares
{
public:
    int point_counter[1001][1001];
    vector<int> ylist_on_x[1001];

    DetectSquares()
    {
        for (int i = 0; i < 1001; i++)
            fill(point_counter[i], point_counter[i] + 1001, 0);
    }

    void add(vector<int> point)
    {
        point_counter[point[0]][point[1]]++;
        ylist_on_x[point[0]].push_back(point[1]);
    }

    int count(vector<int> point)
    {
        int x1 = point[0];
        int y1 = point[1];

        int cnt = 0;
        for (int y2 : ylist_on_x[x1])
        {
            int side = abs(y1 - y2);
            if (side == 0)
                continue;

            int x2 = x1 - side;
            if (x2 >= 0)
                cnt += point_counter[x2][y1] * point_counter[x2][y2];

            int x3 = x1 + side;
            if (x3 <= 1000)
                cnt += point_counter[x3][y1] * point_counter[x3][y2];
        }

        return cnt;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */

/*
(Runtime, Memory) = (75.56%, 16.00%)
add는 O(1), count는 O(N), space는 O(N^2).
공간이 크지 않아 2차원 배열을 썼는데 unordered_multiset을 쓰면 O(N)이다.
ylist_on_x는 point 개수만큼만 공간을 쓰므로 O(N).
모든 점 3개 조합을 확인하면 O(N^3)이지만 같은 x좌표에 있는 점 하나로
나머지 점 2개의 위치를 계산할 수 있으므로 O(N)만에 count가 가능하다.
unordered_multiset 써도 2차원 배열처럼 O(1)에 좌표 확인이 가능하긴 하겠지만
pair hash가 안돼서 좌표별로 set을 따로 쓰거나 hash 함수를 직접 만들어야 한다.
만들더라도 set이 배열보다 검색이 빠르진 않으니 메모리 부족이 아니면 굳이 할 필요 없다.
*/