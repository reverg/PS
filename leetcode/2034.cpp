class StockPrice
{
    int latest_time;
    unordered_map<int, int> timestamps;
    priority_queue<pair<int, int>> max_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_heap;

public:
    StockPrice()
    {
        latest_time = 0;
    }

    void update(int timestamp, int price)
    {
        latest_time = max(latest_time, timestamp);
        timestamps[timestamp] = price;
        max_heap.emplace(price, timestamp);
        min_heap.emplace(price, timestamp);
    }

    int current() { return timestamps[latest_time]; }

    int maximum()
    {
        while (timestamps[max_heap.top().second] != max_heap.top().first)
            max_heap.pop();

        return max_heap.top().first;
    }

    int minimum()
    {
        while (timestamps[min_heap.top().second] != min_heap.top().first)
            min_heap.pop();

        return min_heap.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

/*
(Runtime, Memory) = (92.35%, 91.76%)
maximum, minimum에 쓸 heap 각각 1개랑 시간 기록할 map이 필요하다.
heap에서 임의의 원소를 찾으려면 다 뒤져봐야 하므로 가장 최근 가격만
가지고 있으면 O(N^2)이 된다. 메모리를 좀 더 써서 map에 시간들을
기록해두고 heap의 데이터가 일치하지 않으면 버리는 방식이 낫다.
시간은 O(NlogN), 공간은 O(N)이다.
*/