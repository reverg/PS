class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max_elem = *max_element(arr.begin(), arr.end());

        int cur = arr[0];
        int win_streak = 0;
        
        for(int i=1; i<arr.size(); i++)
        {
            int opponent = arr[i];

            if(cur > opponent)
                win_streak++;
            else{
                cur = opponent;
                win_streak = 1;
            }

            if(win_streak == k || cur == max_elem)
                return cur;
        }

        return -1;
    }
};

/*
(Runtime, Memory) = (86.49%, 32.94%).
N명이 K연승을 할 때까지 하는데, 굳이 K연승을 할 때까지 돌려볼 필요는 없다.
최대인 원소가 맨 앞까지 오면 늘 이기게 되므로 시뮬레이션을 바로 중지해도
무방하고, 시간복잡도는 O(N)이 된다. 큐를 사용하면 간단하게 구현 가능하지만
공간복잡도가 O(N)이다. 어차피 한번 진 사람은 그 사람의 차례가 돌아오기 전에
최대 원소가 오기 때문에 굳이 뒤로 보낼 필요가 없고, 이를 배열로 처리하면
현재 코드처럼 O(1)에 처리 가능하다. 결론적으로 시간 O(N), 공간 O(1)에 작동.
*/