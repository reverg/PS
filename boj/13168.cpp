#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int N, R, M, K;
vector<int> tourList;
double naeilo[100][100];
double ilban[100][100];
unordered_map<string, int> cityCode;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

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
        fill(naeilo[i], naeilo[i] + N, INF);
        fill(ilban[i], ilban[i] + N, INF);
        naeilo[i][i] = 0;
        ilban[i][i] = 0;
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

/*
내일로 살 때와 안 살 때 금액을 분리해서 따로 플로이드 쓰면 된다.
여행 경로 따라 금액 확인한 뒤 싼지 안싼지 비교해서 싼 것 출력.
*/