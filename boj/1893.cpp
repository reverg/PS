// reference: https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x1E/solutions/1893.cpp
#include <iostream>
#include <vector>

using namespace std;

string A, W, S;
int original_alphabets[257]; // 8-bit ASCII
int shifted_alphabets[257];  // 8-bit ASCII
vector<int> f;
int cnt[63];
vector<int> ans;

vector<int> failure(string &s)
{
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++)
    {
        while (j > 0 && s[i] != s[j])
            j = f[j - 1];
        if (s[i] == s[j])
            f[i] = ++j;
    }
    return f;
}

void solve()
{
    int as = A.size();
    // shift해서 만들 수 있는 모든 문자열에 대해 확인
    for (int k = 0; k < as; k++)
    {
        // 문자열 shift
        for (int i = 0; i < as; i++)
            shifted_alphabets[A[i]] = (original_alphabets[A[i]] + k) % as;

        // KMP
        int j = 0;
        for (int i = 0; i < S.size(); i++)
        {
            while ((j > 0) && (original_alphabets[S[i]] != shifted_alphabets[W[j]]))
                j = f[j - 1];
            if (original_alphabets[S[i]] == shifted_alphabets[W[j]])
                j++;

            if (j == W.size())
            {
                j = f[j - 1];
                cnt[k]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        f.clear();
        ans.clear();
        fill(cnt, cnt + 63, 0);

        cin >> A >> W >> S;
        for (int i = 0; i < A.size(); i++)
            original_alphabets[A[i]] = i;

        f = failure(W); // failure function
        solve();

        for (int k = 0; k < A.size(); k++)
        {
            if (cnt[k] == 1)
                ans.push_back(k);
        }

        if (ans.size() == 0)
            cout << "no solution\n";
        else if (ans.size() == 1)
            cout << "unique: " << ans[0] << '\n';
        else
        {
            cout << "ambiguous: ";
            for (int a : ans)
                cout << a << ' ';
            cout << '\n';
        }
    }
}

/*
KMP.
shift해서 만들 수 있는 문자열 종류가 최대 62이므로 다 확인해봐도 시간이 충분하다.
shift하는 부분은 ASCII 배열(문자 256종류)을 따로 둬서 처리.
*/