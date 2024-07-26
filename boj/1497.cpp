// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/Appendix%20C/1497.cpp
#include <iostream>

using namespace std;

int N, M;

int bit_cnt(long long x)
{
    int ret = 0;
    for (int i = 0; i < max(N, M); i++)
        ret += (x >> i) & 1;
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    long long state[10] = {0};
    for (int i = 0; i < N; i++)
    {
        string name, tmp;
        cin >> name >> tmp;
        for (int j = M - 1; j >= 0; j--)
            state[i] = (state[i] << 1) | (tmp[j] == 'Y');
    }

    pair<int, int> ans = {0, -1};
    for (int tmp = 0; tmp < (1 << N); tmp++)
    {
        // 기타가 최대 10개: 1024개 조합 다 확인해봐도 충분
        long long comb = 0;
        for (int i = 0; i < N; i++)
        {
            if ((tmp & (1LL << i)) == 0)
                continue;
            comb |= state[i];
        }

        int song_num = bit_cnt(comb);
        int guitar_num = bit_cnt(tmp);
        if (ans.first < song_num)
            ans = {song_num, guitar_num};
        else if (ans.first == song_num && ans.second > guitar_num)
            ans = {song_num, guitar_num};
    }

    cout << ans.second << '\n';
}