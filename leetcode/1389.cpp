class Solution
{
public:
    vector<int> createTargetArray(vector<int> &nums, vector<int> &index)
    {
        vector<int> targetArray;
        for (int i = 0; i < nums.size(); i++)
            targetArray.insert(targetArray.begin() + index[i], nums[i]);

        return targetArray;
    }
};

/*
(Runtime, Memory) = (100.00%, 49.96%).
STL로 벡터에 매번 insert하면 O(N^2) 풀이가 된다. O(NlogN) 풀이가 있나 생각해보다
{index[i], -i}를 넣은 벡터를 만들어서 sorting하고 결과물 앞부터 nums[i]를 찾아
집어넣으면 답이 아닐까? 라는 생각이 들었지만 오답이었다. 뒷부분에서 기존 숫자들의
앞쪽에 넣어버리면 삽입된 곳 뒤쪽 인덱스들이 모조리 바뀌어버리기 때문에 뒤쪽에 나온
인덱스 1에 삽입이 앞쪽에 나왔던 인덱스 0보다 앞에 삽입되는 경우가 나온다. 아래 반례를
참고하자. 아무튼 O(N^2)이 최적 풀이가 맞는 것 같은데 증명은 능력 밖이라 넘긴다.

반례와 틀린 코드: 
nums = [4,2,4,3,2], index = [0,0,1,3,1] / Output = [2,4,2,4,3], Expected = [2,2,4,4,3]

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<pair<int, int>> order;
        for(int i=0; i<nums.size(); i++)
            order.emplace_back(index[i], -i);
        
        sort(order.begin(), order.end());

        vector<int> targetArray;
        for(int i=0; i<nums.size(); i++){
            targetArray.push_back(nums[-order[i].second]);
        }

        return targetArray;
    }
};
*/