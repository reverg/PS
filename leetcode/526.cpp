class Solution
{
public:
    void backtrack(int n, int cur, vector<int> &used, int &cnt)
    {
        if (cur == n + 1)
        {
            cnt++;
            return;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!used[i] && (cur % i == 0 || i % cur == 0))
            {
                used[i] = 1;
                backtrack(n, cur + 1, used, cnt);
                used[i] = 0;
            }
        }
    }

    int countArrangement(int n)
    {
        int cnt = 0;
        vector<int> used(n + 1);

        backtrack(n, 1, used, cnt);

        return cnt;
    }
};

/*
(Runtime, Memory) = (67.12%, 60.89%). #526 -> #667인데 그닥 연관성이 없다.
모든 permutation을 생성해서 확인해보는건 답이 없다. 백트래킹을 쓰면 중간에
가지치기가 되니까 좀 낫다.
처음에는 ba[n] = ba[n-1] + ... 형태의 쉬운 식이 있어서 dp로 풀리지 않을까 하는
생각을 했었는데, 추가되는 수가 올 수 있는 위치가 매번 달라져서 쉬운 식이 있을 수가
없다는 걸 깨달았다. 다음에는 맨 아래 방식처럼 3차원 dp를 시도했지만 모든 숫자가
각 위치에 올 수 있는 가짓수가 얼마나 되는지 확인하는게 답 없는 작업이란걸 깨닫고 접었다.

    // 1 -> everywhere
    // 2 -> 1, 2
    // 3 -> 1, 3
    // 4 -> 1, 2, 4
    // 5 -> 1, 5
    // 6 -> 1, 2, 3, 6
    // if last number goes to end: ba[n] += ba[n-1]
    // if last number goes to begin: ba[n] += ba[n-1, begin=1]
    // if last number goes to divisor: ba[n] += ba[n-1, divisor=divisor]
    // set dp array ba[len][num][loc] ...
*/