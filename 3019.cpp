#include <iostream>
#include <string>
using namespace std;

int C, P;
int a[101];

int go(int idx, string s) {
	if (idx + s.length() > C) return 0;
	int base = a[idx] - (s[0] - '0');
	for (int i = 0; i < s.length(); i++) {
		if (base != a[idx + i] - (s[i] - '0')) {
			return 0;
		}
	}
	return 1;
}
int main() {
	cin >> C >> P;
	for (int i = 0; i < C; i++) {
		cin >> a[i];
	}

	int ans = 0;
	for (int i = 0; i < C; i++) {
		if (P == 1) {
			ans += go(i, "0") + go(i,"0000");
		}
		else if (P == 2) {
			ans += go(i, "00");
		}
		else if (P == 3) {
			ans += go(i, "001") + go(i, "10");
		}
		else if (P == 4) {
			ans += go(i, "100") + go(i, "01");
		}
		else if (P == 5) {
			ans += go(i, "000") + go(i, "101") + go(i, "01") + go(i, "10");
		}
		else if (P == 6) {
			ans += go(i, "000") + go(i, "20") + go(i, "00") + go(i, "011");
		}
		else if (P == 7) {
			ans += go(i, "000") + go(i, "02") + go(i, "110") + go(i, "00");
		}
	}
	cout << ans << '\n';
}