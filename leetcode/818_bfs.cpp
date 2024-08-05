class Solution
{
public:
    int racecar(int target)
    {
        queue<tuple<int, int, int>> q;
        q.emplace(0, 1, 0);

        while (!q.empty())
        {
            auto [pos, speed, count] = q.front();
            q.pop();

            if (pos == target)
                return count;

            if (pos > 2 * target || pos < 0)
                continue;

            q.emplace(pos + speed, speed * 2, count + 1);
            if ((pos + speed) < target && speed < 0)
                q.emplace(pos, 1, count + 1);
            else if ((pos + speed) > target && speed > 0)
                q.emplace(pos, -1, count + 1);
        }

        return 0;
    }
};

/*
(Runtime, Memory) = (100.00%, 63.00%)
BFS 풀이. 1...1 꼴의 이진수들로 합/차를 적절히 해서 target을 만들어야 한다.
17~18행이 pos의 범위를 제한하는 핵심 부분이다. 컷팅을 잘 해주지 않으면 메모리나
시간 문제가 생길 수 있다. 범위를 확정해줬으므로 visited 배열을 추가로 쓰면 조금
더 시간 효율적으로 짤 수 있다. 증명은 일부만 됐는데 일단 아래와 같다.

pos < 0: (++)(+-+-)(--)로 배치하자. +는 큰 순서대로, -는 0에 가까운 순서대로 한다.
    이러면 방향전환이 최소로 발생하므로 최적의 배치가 되고, 모든 구간에서 누적합이 0
    이상이 된다. 누적합이 음수인 부분이 발생하려면 +- 쌍이 0보다 작은 부분이 있고,
    이게 누적돼서 합이 음수가 되어야 한다. 그런데 상술한 방식으로 배치하면 +-쌍의 합의
    크기가 점점 감소하므로 뒷부분 합도 모조리 음수가 되고, target > 0을 만들수가 없다.
    따라서 음수인 부분이 발생하지 않는다.
pos > 2 * target: 정확히는 target과 비트 수가 같은 1...1을 넘어갈 필요가 없다.
    뒷부분의 비트를 조작하기 위해 비트 수가 더 큰 1...1을 조작하는 것은 큰 부분을
    다시 무효화시켜야 하므로 추가적인 연산이 든다. 1...1 - 1...1을 적절히 잘 해서
    원하는 연산을 빠르게 할 수 있지 않을까 하는 의문이 있긴 한데 잘 증명되진 않아서
    일단 넘긴다.

p.s. 최적전략 자체를 찾아보겠다는 시도를 했었다.
가장 큰 비트부터 순서대로 조작해서 맞춰보려 했는데
4가 (1+2+4) - (1+2)보다 (1+2) + 1이 빨라서 망했다.
혹시 몰라서 코드는 아래에.

class Solution {
public:
    int racecar(int target) {
        int bitlen = 1;
        while (target >= (1 << bitlen))
            bitlen++;

        int cnt = 0;
        cnt += bitlen;

        int prev_bit = 1;
        for (int i = bitlen - 2; i >= 0; i--) {
            int cur_bit = (target >> i) & 1;
            if (prev_bit != cur_bit) {
                cnt += i + 2;
                prev_bit = cur_bit;
            }
        }

        return cnt;
    }
};
*/