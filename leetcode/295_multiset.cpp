class MedianFinder
{
    multiset<int> data;
    multiset<int>::iterator mid;

public:
    MedianFinder()
        : mid(data.end())
    {
    }

    void addNum(int num)
    {
        const int n = data.size();
        data.insert(num);

        if (!n) // first element inserted
            mid = data.begin();
        else if (num < *mid) // median is decreased
            mid = (n & 1 ? mid : prev(mid));
        else // median is increased
            mid = (n & 1 ? next(mid) : mid);
    }

    double findMedian()
    {
        const int n = data.size();
        return ((double)*mid + *next(mid, n % 2 - 1)) * 0.5;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

/*
(Runtime, Memory) = (27.09%, 5.40%)
mid iterator가 가리키고 있는 수보다 큰 수가 들어오는지 작은 수가 들어오는지를
확인해서 mid iterator를 조작한다. delete도 비슷한 방식으로 iterator를 조작해주면
되니까 메리트가 있다. 다만 bst를 만드는 내부 동작 방식 때문에 constant가 안 좋다.
시간/공간복잡도는 heap을 사용한 것과 완벽하게 동일.
*/