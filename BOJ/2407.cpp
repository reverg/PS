#include <iostream>
#include <string>
using namespace std;

// copied! (https://uigwonblog.tistory.com/6)
string table_combi[105][105];

string add(string num1, string num2) {
	string ans = "";
	int sum = 0;
	int size = max(num1.size(), num2.size());

	for (int i = 0; i < size || sum; i++) {
		if (num1.size() > i) sum += num1[i] - '0';
		if (num2.size() > i) sum += num2[i] - '0';

		ans += sum % 10 + '0';

		sum /= 10;
	}

	return ans;
}

string Combi(int n, int m) {
	if (n == m || m == 0) return "1";
    
	if (table_combi[n][m] != "") return table_combi[n][m];

	// nCm = n-1Cm-1 + n-1Cm
	return table_combi[n][m] = add(Combi(n - 1, m - 1), Combi(n - 1, m));
}

int main() {
	int n, m;
	cin >> n >> m;

	Combi(n, m);

	for (int i = table_combi[n][m].size() - 1; i >= 0; i--) {
		cout << table_combi[n][m][i];
	}

	return 0;
}