#include <iostream>
#include <cstring>
using namespace std;

long long P[51][51][51][51];

long long go(int s, int d, int k, int h) {
	if (s == 0) {
		if (d == 0 && k == 0 && h == 0) return 1;
		else return 0;
	}
	if (d < 0 || k < 0 || h < 0) return 0;
	long long& ans = P[s][d][k][h];
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int m = 0; m < 2; m++) {
				if (i + j + m == 0) continue;
				ans += go(s - 1, d - i, k - j, h - m);
			}
		}
	}
	ans %= 1000000007;
	return ans;
}

int main() {
	int S, D, K, H;
	cin >> S >> D >> K >> H;
	memset(P, -1, sizeof(P));
	cout << go(S, D, K, H) << '\n';
	return 0;
}