#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const long long mod = 100000;
int N;
string s;
long long D[201][201];
string open = "({[";
string close = ")}]";


long long go(int p, int q) {
	if (p > q) {
		return 1;
	}
	long long &ans = D[p][q];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (int j = p + 1; j <= q; j+=2) {
		for (int i = 0; i < 3; i++) {
			if (s[p] == open[i] || s[p] == '?') {
				if (s[j] == close[i] || s[j] == '?') {
					long long temp = go(p + 1, j - 1) * go(j + 1, q);
					ans += temp;
					if (ans >= mod) {
						ans = mod + ans % mod;
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> N;
	cin >> s;
	memset(D, -1, sizeof(D));
	long long ans = go(0, N - 1);
	if (ans >= mod) {
		printf("%05lld\n", ans % mod);
	}
	else {
		printf("%lld\n", ans);
	}
	return 0;
}