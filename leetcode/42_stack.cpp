class Solution
{
public:
    int trap(vector<int> &height)
    {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size())
        {
            while (!st.empty() && height[current] > height[st.top()])
            {
                int top = st.top();
                st.pop();
                if (st.empty())
                    break;
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;
    }
};

/*
(Runtime, Memory) = (6.54%, 5.37%)
스택을 이용한 풀이. 현재 높이가 스택의 탑 부분 높이 이하면 인덱스를 스택에 넣는다.
현재 높이가 스택의 탑 높이보다 커지면 스택의 탑과 현재 위치 사이에 물이 고일 수 있다는 뜻이다.
다음 탑까지의 거리를 구해서 높이 차이와 곱하면 고일 수 있는 물의 양이 된다.
풀이가 좀 비직관적인데 dp는 물을 세로로, stack은 물을 가로로 채우는 느낌이라고 보면 될 것 같다.
다만 dp가 연산이 워낙 간단해서 그런지 훨씬 빠르게 동작한다.
백준 #1725와 비슷한 느낌이라 참고하면 좋을 것 같다.
*/