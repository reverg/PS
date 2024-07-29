class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            if(grid[i][0] != 0){
                for(int j=1; j<n; j++) // flip row
                    grid[i][j] = (grid[i][j] == 1 ? 0 : 1);
            }
        }

        bool can_remove_ones = true;
        for(int j=1; j<n; j++){
            int row_standard = grid[0][j];
            for(int i=1; i<m; i++){
                if(grid[i][j] != row_standard){
                    can_remove_ones = false;
                    break;
                }
            }
            if(!can_remove_ones)
                break;
        }

        return can_remove_ones;
    }
};

/*
column과 row별로만 뒤집기가 가능하므로 대한 1개 column을 다 0으로 맞춘 후엔 나머지
column에 0과 1이 섞인 경우가 있으면 안된다. 0번 column을 0으로 다 맞춰준 후 다른
column들이 모두 같은 수로 이루어져 있는지 확인했다.
*/