int getPow(int x)
{
    int cnt = 0;
    while (x != 1)
    {
        if (x % 2 == 0)
            x /= 2;
        else
            x = 3 * x + 1;

        cnt++;
    }

    return cnt;
}

bool comp(int a, int b)
{
    int pa = getPow(a);
    int pb = getPow(b);

    if (pa == pb)
        return a < b;
    else if (pa < pb)
        return true;
    else
        return false;
}

class Solution
{
public:
    int getKth(int lo, int hi, int k)
    {
        vector<int> v;
        for (int i = lo; i <= hi; i++)
            v.push_back(i);

        sort(v.begin(), v.end(), comp);

        return v[k - 1];
    }
};

/*
power값을 다 계산해서 pair로 만들어놓고 정렬시키는 것이 더 편하다.
sort에 임의 함수 넘기는 것 연습하려고 이렇게 함.
*/