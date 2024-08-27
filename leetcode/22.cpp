class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> paran_parts(n + 1, vector<string>());
        paran_parts[0].emplace_back("");
        paran_parts[1].emplace_back("()");

        for (int k = 2; k <= n; k++)
        {
            for (int i = 0; i <= k - 1; i++)
            {
                for (string s1 : paran_parts[i])
                    for (string s2 : paran_parts[k - i - 1])
                        paran_parts[k].emplace_back("(" + s1 + ")" + s2);
            }
        }

        return paran_parts[n];
    }
};

/*
(Runtime, Memory) = (64.99%, 98.03%)
분할정복으로 해결했다. 괄호 K개를 사용한 문자열은 0+K, ..., K+0개 사용한
문자열들로 만들어진다. 다만 직전 결과들을 이어붙이는 방식으로만 만들면 괄호를
밖에 두르는 경우가 고려되지 않는다. 그래서 (0)+K-1, ..., (K-1)+0개 형식으로
만들어야 모든 경우를 찾을 수 있다. 모든 경우의 수는 (2^2N / (N sqrt(N))이고,
string 조합 부분이 O(N)이므로 시간복잡도는 O(4^N / sqrt(N))이다. 왜 경우의 수가
저런지는 카탈란 수를 찾아보자. 공간복잡도는 답이 차지하는 메모리 때문에 시간복잡도와
같게 나온다. 답 부분을 빼도 현재 코드에서 직전 결과들을 저장해두고 있으므로 동일.

backtracking으로 여는 괄호가 닫는 괄호보다 많게 유지하는 풀이도 가능하다.
당연히 시간복잡도와 공간복잡도는 동일하다.
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> answer;
        backtracking(answer, "", 0, 0, n);
        return answer;
    }

private:
    void backtracking(vector<string> &answer, string curString, int leftCount,
                      int rightCount, int n)
    {
        if (curString.size() == 2 * n)
        {
            answer.push_back(curString);
            return;
        }
        if (leftCount < n)
        {
            curString += '(';
            backtracking(answer, curString, leftCount + 1, rightCount, n);
            curString.pop_back();
        }
        if (leftCount > rightCount)
        {
            curString += ')';
            backtracking(answer, curString, leftCount, rightCount + 1, n);
            curString.pop_back();
        }
    }
};
*/