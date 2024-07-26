#include <iostream>
#include <algorithm>

using namespace std;

struct Box
{
    int sender;
    int reciever;
    int count;
};

bool compBox(Box b1, Box b2)
{
    if (b1.reciever != b2.reciever)
        return b1.reciever < b2.reciever;
    else
        return b1.sender < b2.sender;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, C, M;
    cin >> N >> C;
    cin >> M;

    Box boxes[10000];
    for (int i = 0; i < M; i++)
        cin >> boxes[i].sender >> boxes[i].reciever >> boxes[i].count;

    sort(boxes, boxes + M, compBox);

    int ans = 0;
    int truckCapacity[10001] = {0};
    for (int i = 0; i < M; i++)
    {
        int max_delivering = 0;
        for (int j = boxes[i].sender; j < boxes[i].reciever; j++)
            max_delivering = max(truckCapacity[j], max_delivering);

        int deliver = min(boxes[i].count, C - max_delivering);
        ans += deliver;

        for (int j = boxes[i].sender; j < boxes[i].reciever; j++)
            truckCapacity[j] += deliver;
    }

    cout << ans << '\n';
}