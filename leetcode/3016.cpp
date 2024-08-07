class Solution
{
public:
    int minimumPushes(string word)
    {
        int alphabet_counter[26];
        for (char c : word)
            alphabet_counter[c - 'a']++;

        sort(alphabet_counter, alphabet_counter + 26, greater<int>());

        int cost_sum = 0;
        for (int i = 0; i < 26; i++)
        {
            int cost = (i / 8) + 1;
            cost_sum += cost * alphabet_counter[i];
        }

        return cost_sum;
    }
};

/*
(Runtime, Memory) = (89.01%, 57.94%)
그리디 문제. 빈도수가 많은 알파벳을 조금 누르게 키를 배정하면 된다.
키가 8개여서 1~8번째는 1, 9~16번째는 2... 형태로 cost가 설정된다.
증명은 빈도수가 많은 알파벳을 적은 cost에 배정하는 것과 키를 골고루
배치하는게 이득임을 증명하면 된다. 둘 다 귀류법 쓰면 간단.
시간복잡도 O(NlogN), 공간복잡도 O(N)이지만 알파벳이 26개 뿐이라 의미는 없다.
처음엔 map에 저장해 풀었는데 알파벳 개수가 26개 뿐이라 안 쓰는 알파벳이
많아도 그냥 배열 쓰는게 이득이다... 적절한 자료구조를 선택하는 연습을 하자.
참고로 map에서 배열로 정렬할 경우 vector에 map을 복사해와서 해야 하므로 오래 걸린다.
*/