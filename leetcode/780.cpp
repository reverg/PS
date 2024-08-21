class Solution
{
public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        while (tx >= sx && ty >= sy)
        {
            if (tx == ty)
                break;
            if (tx > ty)
            {
                if (ty > sy)
                    tx %= ty;
                else
                    return (tx - sx) % ty == 0;
            }
            else
            {
                if (tx > sx)
                    ty %= tx;
                else
                    return (ty - sy) % tx == 0;
            }
        }
        return (tx == sx && ty == sy);
    }
};

/*
(Runtime, Memory) = (100.00%, 44.17%).
수학 문제다. (x, y) -> (x+y, y)인 경우에 (x+y) % y = x로 이전 숫자쌍으로 돌아올 수 있다.
n번 더해서 (nx+y, y) 된 경우도 상관없다. 계속 큰 것을 작은 것으로 나눈 나머지로 바꿔서
(sx, sy)로 돌아올 수 있으면 true, 돌아갔는데 값이 안 맞으면 false. 시간 O(log(max(tx, ty))),
공간 O(1)에 풀린다.

다른 방법으로 DP를 가미한 BFS가 있는데, 시간과 공간 모두 O(tx*ty)여서 최적의 해법이 아니다.

조금 더 나은 방법으로 큰 수 - 작은 수를 반복해서 (sx, sy)가 나오나 확인하는 방법이 있다.
숫자 2개 중 큰 것이 최근에 더해진 것임을 이용하는 방법인데 시간 O(max(tx, ty))가 나와서 나누기를
하는 방법보다 별로다. 공간은 O(1).
*/