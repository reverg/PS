class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost)
    {
        long long char_dist[26][26];
        for (int i = 0; i < 26; i++)
        {
            fill(char_dist[i], char_dist[i] + 26, 1e8);
            char_dist[i][i] = 0;
        }
        for (int i = 0; i < original.size(); i++)
        {
            if (char_dist[original[i] - 'a'][changed[i] - 'a'] > cost[i])
                char_dist[original[i] - 'a'][changed[i] - 'a'] = cost[i];
        }

        // Floyd-warshall: O(N^3)
        for (int mid = 0; mid < 26; mid++)
        {
            for (int from = 0; from < 26; from++)
            {
                for (int to = 0; to < 26; to++)
                {
                    if (char_dist[from][to] >
                        char_dist[from][mid] + char_dist[mid][to])
                        char_dist[from][to] =
                            char_dist[from][mid] + char_dist[mid][to];
                }
            }
        }

        bool convertable = true;
        long long sum_cost = 0;
        for (int i = 0; i < source.length(); i++)
        {
            long long dist = char_dist[source[i] - 'a'][target[i] - 'a'];
            if (dist < 1e8)
            {
                sum_cost += dist;
            }
            else
            {
                convertable = false;
                break;
            }
        }

        if (convertable)
            return sum_cost;
        else
            return -1;
    }
};

/*
map에 {{original, changed}, cost}를 넣고 바꿔주는 방법을 처음 시도했지만
a->c->b로 바꾸는 것도 고려해줘야 해서 틀린 풀이다. 플로이드-워셜이 정해.
*/