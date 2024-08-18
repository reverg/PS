class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();

        int r = m - 1;
        int c = 0;
        while (r >= 0 && c < n)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                r--;
            else
                c++;
        }

        return false;
    }
};
/*
(Runtime, Memory) = (78.34%, 29.10%), #74 -> #240
행/열별로만 정렬되어 있게 조건이 바뀌어서 BS를 쓸 수 없어졌다.
1열에 대해서 lower_bound와 upper_bound로 가능한 열 범위를 구하고,
행에 대해서 다시 lower_bound로 답을 찾으면 최악의 경우 O(MlogN) 풀이가 된다.

matrix[r][c] >= matrix[r'][c'] (r'<=r, c'<=c)임을 잘 이용하면 훨씬 빠르게 풀 수 있다.
matrix[m-1][0]에서 1칸씩 움직이면서 답에 가까워지는 방법을 쓰면 최대 세로 M칸, 가로 N칸
움직이므로 시간 O(M+N), 공간 O(1)에 풀린다. 처음에는 대각선으로 1칸씩 움직이다가 r, c를
조정하는 방식을 시도했는데 완벽하게 커버되지 않아서 실패했었다...
*/