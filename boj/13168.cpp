#include <iostream>
#include <unordered_map>
#include <vector>

#define INF 1e9

using namespace std;
unordered_map<string, int> cityCode;

int main()
{
    int N, R, M, K;
    vector<int> tourList;
    double naeilo[100][100] = {0};
    double ilban[100][100] = {0};

    // map string to int: city name -> city code
    cin >> N >> R;
    for (int i = 0; i < N; i++)
    {
        string city;
        cin >> city;
        cityCode[city] = i;
    }

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        string city;
        cin >> city;
        tourList.push_back(cityCode[city]);
    }

    cin >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i != j)
            {
                naeilo[i][j] = INF;
                ilban[i][j] = INF;
            }
        }
    }
    for (int i = 0; i < K; i++)
    {
        string type, start, end;
        double cost;
        cin >> type >> start >> end >> cost;

        int s = cityCode[start];
        int e = cityCode[end];
        ilban[s][e] = min(ilban[s][e], cost);
        ilban[e][s] = min(ilban[e][s], cost);

        if (type == "Mugunghwa" || type == "ITX-Saemaeul" || type == "ITX-Cheongchun")
        {
            naeilo[s][e] = 0;
            naeilo[e][s] = 0;
        }
        else if (type == "S-Train" || type == "V-Train")
        {
            naeilo[s][e] = min(naeilo[s][e], cost / 2);
            naeilo[e][s] = min(naeilo[e][s], cost / 2);
        }
        else
        {
            naeilo[s][e] = min(naeilo[s][e], cost);
            naeilo[e][s] = min(naeilo[e][s], cost);
        }
    }

    // floyd-warshall
    for (int mid = 0; mid < N; mid++)
    {
        for (int from = 0; from < N; from++)
        {
            for (int to = 0; to < N; to++)
            {
                ilban[from][to] = min(ilban[from][to], ilban[from][mid] + ilban[mid][to]);
                naeilo[from][to] = min(naeilo[from][to], naeilo[from][mid] + naeilo[mid][to]);
            }
        }
    }

    double ilban_cost = 0;
    double naeilo_cost = R;
    for (int i = 0; i < M - 1; i++)
    {
        ilban_cost += ilban[tourList[i]][tourList[i + 1]];
        naeilo_cost += naeilo[tourList[i]][tourList[i + 1]];
    }

    cout << (ilban_cost > naeilo_cost ? "Yes" : "No") << '\n';
}