class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, 1e6));
        for(int i=0; i<n; i++)
            dist[i][i] = 0;
        for(auto e : edges){
            dist[e[0]][e[1]] = e[2];
            dist[e[1]][e[0]] = e[2];
        }
        
        // floyd-warshall
        for(int mid = 0; mid < n; mid++){
            for(int from = 0; from < n; from++){
                for(int to = 0; to <n; to++){
                    if(dist[from][to] > dist[from][mid] + dist[mid][to])
                        dist[from][to] = dist[from][mid] + dist[mid][to];
                }
            }
        }

        int min_neighbors = 100;
        int ans_city = -1;
        for(int i=0; i<n; i++){
            int cur_neighbors = -1;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold)
                    cur_neighbors++;
            }
            if(cur_neighbors <= min_neighbors){
                min_neighbors = cur_neighbors;
                ans_city = i;
            }
        }

        return ans_city;
    }
};

/*
플로이드-워셜 문제. 모든 도시간의 거리를 구해야 해서 O(N^3)이다.
N <= 100이고 도로 거리도 최대 1e4라 int 써도 무방하다.
*/