#include <iostream>
#include <cstring>
using namespace std;

long long D[5001];
long long mod = 1000000007;

long long go(int N) {
	if (N == 0) return 1;
	if (D[N] != -1) return D[N];
	D[N] = 0;
	for (int i = 2; i <= N; i++) {
		D[N] += go(i - 2) * go(N - i);
		D[N] %= mod;
	}
	return D[N];
}

int main() {

	int T;
	cin >> T;
	memset(D, -1, sizeof(D));
	while (T--) {
		int L;
		cin >> L;
		if (L % 2 == 0) {
			cout << go(L) << '\n';
		}
		else {
			cout << "0\n";
		}
	}
}