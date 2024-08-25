class Solution
{
public:
    pair<int, int> expand(int i, int j, string &s)
    {
        int left = i;
        int right = j;

        while (left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }

        return {left + 1, right - 1};
    }

    string longestPalindrome(string s)
    {
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            pair<int, int> odd = expand(i, i, s);
            int odd_size = odd.second - odd.first + 1;
            if (odd_size > ans.size())
                ans = s.substr(odd.first, odd.second - odd.first + 1);

            pair<int, int> even = expand(i, i + 1, s);
            int even_size = even.second - even.first + 1;
            if (even_size > ans.size())
                ans = s.substr(even.first, even.second - even.first + 1);
        }

        return ans;
    }
};

/*
(Runtime, Memory) = (73.01%, 61.97%)
string의 중간 점을 잡고 좌우로 늘려가면서 최대 palindrome을 찾는 방식.
n개의 홀수 길이 시작점, n-1개의 짝수 길이 시작점에서 길이 n까지 늘어나므로
시간 O(N^2)에 풀린다. 공간은 O(1).

시간과 공간 모두 O(N)에 푸는 Manacher's algorithm이란게 있다고 한다.
뭐 이걸 물어보진 않으리라 생각한다...

흔히 보이는 DP 풀이는 시간은 똑같이 O(N^2)지만 공간이 O(N^2)이다. 현재 코드와는
달리 모든 substr을 다 확인하므로 시간 상수도 안 좋다. 코드는 아래 참고.

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        pair<int, int> ans_interval = {0, 0};

        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                ans_interval = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; diff++)
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    ans_interval = {i, j};
                }
            }
        }

        return s.substr(ans_interval.first, ans_interval.second - ans_interval.first + 1);
    }
};
*/