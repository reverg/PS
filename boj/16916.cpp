#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string S, P;
    cin >> S >> P;

    char *ptr = strstr((char *)S.c_str(), (char *)P.c_str());
    cout << (ptr != NULL) << '\n';
}

/*
strstr이 선형 시간에 동작하므로 단순히 존재만을 확인할 때는 굳이 KMP를 사용하지 않아도 된다.
*/