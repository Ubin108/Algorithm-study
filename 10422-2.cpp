#include <iostream>
#include <cstring>
using namespace std;

long long D[5001][5001];
long long mod = 1000000007;


int main() {

	D[0][0] = 1;
	for (int i = 1; i <= 5000; i++) {
		for (int j = 0; j <= i; j++) {
			D[i][j] = 0;
			if (j + 1 <= i) {
				D[i][j] += D[i - 1][j + 1];
			}
			if (j - 1 >= 0) {
				D[i][j] += D[i - 1][j - 1];
			}
			D[i][j] %= mod;
		}
	}

	int T;
	cin >> T;
	while (T--) {
		int L;
		cin >> L;
		cout << D[L][0] << '\n';
	}
	return 0;
}