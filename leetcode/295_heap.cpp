class MedianFinder
{
public:
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<>> min_pq;

    MedianFinder()
    {
        // default
    }

    void addNum(int num)
    {
        if (max_pq.size() == min_pq.size())
            max_pq.push(num);
        else
            min_pq.push(num);

        if (min_pq.size() >= 1 && min_pq.top() < max_pq.top())
        {
            int tmp = max_pq.top();
            max_pq.pop();
            max_pq.push(min_pq.top());
            min_pq.pop();
            min_pq.push(tmp);
        }
    }

    double findMedian()
    {
        if (max_pq.size() == min_pq.size())
            return (double)(max_pq.top() + min_pq.top()) / 2;
        else
            return (double)max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
(Runtime, Memory) = (48.25%, 50.50%)
어디서 많이 본 문제. 2개의 우선순위 큐를 쓰면 median을 쉽게 구할 수 있다.
addNum은 O(logN), findMedian은 O(1)에 수행된다. 다만 특정 상황(19~26행)에서는
추가적으로 큐의 push/pop이 실행되어 최악의 경우엔 연산 횟수가 좀 늘어날 수 있다.
공간복잡도는 큐 2개 써도 원소 이외의 정보를 안 쓰므로 O(N)이다.

배열이 늘어나기만 하고 줄어들진 않아서 우선순위 큐를 사용해도 문제가 없었다.
만약 제거 연산이 있었으면 우선순위 큐를 사용할 수 없다. multiset을 쓰는 다른 풀이 참고.
*/