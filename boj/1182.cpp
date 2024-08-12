#include <iostream>

using namespace std;

int N, S;
int numbers[30];
int cnt = 0;

void part_sum_cnt(int cur, int sum)
{
    int tmp_sum = sum + numbers[cur];
    if (tmp_sum == S)
        cnt++;
    if (cur == N - 1)
        return;

    part_sum_cnt(cur + 1, sum);
    part_sum_cnt(cur + 1, tmp_sum);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> numbers[i];

    part_sum_cnt(0, 0);

    cout << cnt << '\n';
}

/*
소소한 잡기술: 11~15행에서 part_sum_cnt의 cur=N 호출이 안 생기게 끊어버림
함수 호출이 적어져서 시간이 줄어듦. 추가적으로 tmp_sum을 확인하므로 최소 1개의
원소가 포함되게 되어 S=0일 때 부분집합이 공집합인 경우 1가지를 빼주지 않아도 됨.
근데 솔직히 이거 헷갈려서 그냥 cur=N까지 가는 코드가 읽기는 편한 듯.
 */