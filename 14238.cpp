#include <iostream>
#include <string>
using namespace std;

int an = 0, bn = 0, cn = 0;
int n;
char ans[51];
bool D[51][51][51][3][3];

bool go(int a, int b, int c, int i) {
	if (i == n) {
		if (a == an && b == bn && c == cn) {
			return true;
		}
		else {
			return false;
		}
	}
	if (a > an || b > bn || c > cn) return false;
	char pre1 = 'A';
	char pre2 = 'A';
	if (i >= 1) {
		pre1 = ans[i - 1];
	}
	if (i >= 2) {
		pre2 = ans[i - 2];
	}	
	if (D[a][b][c][pre1 - 'A'][pre2 - 'A']) return false;
	D[a][b][c][pre1 - 'A'][pre2 - 'A'] = true;
	if (pre1 == 'A') {
		if (pre2 == 'C') {
			ans[i] = 'A';
			if (go(a + 1, b, c, i + 1)) return true;
			ans[i] = 'B';
			if (go(a, b + 1, c, i + 1)) return true;
			return false;
		}
		else {
			ans[i] = 'A';
			if (go(a + 1, b, c, i + 1)) return true;
			ans[i] = 'B';
			if (go(a, b + 1, c, i + 1)) return true;
			ans[i] = 'C';
			if (go(a, b, c + 1, i + 1)) return true;
			return false;
		}
	}
	else if (pre1 == 'B') {
		if (pre2 == 'C') {
			ans[i] = 'A';
			if (go(a + 1, b, c, i + 1)) return true;
			return false;
		}
		else {
			ans[i] = 'A';
			if (go(a + 1, b, c, i + 1)) return true;
			ans[i] = 'C';
			if (go(a, b, c + 1, i + 1)) return true;
			return false;
		}
	}
	else if (pre1 == 'C') {
		ans[i] = 'A';
		if (go(a + 1, b, c, i + 1)) return true;
		ans[i] = 'B';
		if (go(a, b + 1, c, i + 1)) return true;
		return false;
	}
}

int main() {
	string s;
	cin >> s;
	for (char c : s) {
		if (c == 'A') an++;
		if (c == 'B') bn++;
		if (c == 'C') cn++;
	}
	n = an + bn + cn;
	if (go(0, 0, 0, 0)) {
		cout << ans << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}