class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n <= 0)
            return false;

        long long pow_three = 1;
        while (pow_three <= n)
        {
            if (pow_three == n)
                return true;
            pow_three *= 3;
        }

        return false;
    }
};

/*
(Runtime, Memory) = 실행마다 차이가 큼
그냥 루프 신나게 도는 문제. 1분컷 해야되는 문제다.
loop/recursion 없이 풀 수 있냐는게 follow-up인데,
모르겠어서 기대하면서 leetcode editorial을 열어봤더니

return (n > 0) && (1162261467 % n == 0);

이딴걸 적어놨다. 1162261467은 int 범위에 들어오는 가장 큰
3의 제곱수이다. 어이가 좀 없긴 하지만 pre-computing해서
시간복잡도를 아낄 수 있는 예시라고 기억해두자. N-queen에서
미리 답 구해놓은걸 제출한 풀이가 떠오른다. 후...
*/