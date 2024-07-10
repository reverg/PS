#include <iostream>
#include <string>
#include <vector>

using namespace std;

string text, pattern;
vector<int> pi;

void getPi(string pattern, int L)
{
    pi.resize(L + 1, 0);
    int j = 0;

    for (int i = 1; i < L; i++)
    {
        while ((j > 0) && (pattern[i] != pattern[j]))
            j = pi[j - 1];

        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    // can reduce L by length of common part of prefix & text end part
    int L;
    string text, pattern;

    cin >> L >> text;
    pattern = text;

    getPi(pattern, L);

    cout << L - pi[L - 1];
}

/*
KMP. 문자열이 다시 반복되기 시작하는 부분을 찾아주자.
pi[L-1]이 문자열 전체 중 일치하는 접두사와 접미사의 최대 길이이므로
이걸 전체 문자열 길이에서 뺀게 광고 중 가장 짧은 것의 길이가 된다.
*/