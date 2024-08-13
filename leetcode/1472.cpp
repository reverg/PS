class BrowserHistory
{
public:
    vector<string> visitedURLs;
    int cur_pos;
    int end_pos;

    BrowserHistory(string homepage)
    {
        visitedURLs.push_back(homepage);
        cur_pos = 0;
        end_pos = 0;
    }

    void visit(string url)
    {
        cur_pos++;

        if (cur_pos < visitedURLs.size())
            visitedURLs[cur_pos] = url;
        else
            visitedURLs.push_back(url);

        end_pos = cur_pos;
    }

    string back(int steps)
    {
        cur_pos = max(0, cur_pos - steps);
        return visitedURLs[cur_pos];
    }

    string forward(int steps)
    {
        cur_pos = min(end_pos, cur_pos + steps);
        return visitedURLs[cur_pos];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/*
(Runtime, Memory) = (75.47%, 93.06%)
문제를 좀 이해하기 힘든데, back으로 갔다가 visit하면 쌓여있는 기록들은 더 이상 쓸모가
없어진다. 하지만 back했다 forward으로 돌아갈 수 있으므로 기록을 무작정 지우면 안된다.
기록들을 쌓아두고 덮어씌우되, 끝 지점을 저장해서 뚫고 넘어가지 않도록 하는 것이 깔끔하다.
각 연산의 시간복잡도는 O(1), 총 사용 공간은 O(url 개수 * 길이)이다.
2개의 stack을 활용하는 풀이도 있던데 이건 back/forward에서 pop/push를 step번 하므로 비효율적.
*/