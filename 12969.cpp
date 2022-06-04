#include <iostream>
#include <cstring>
using namespace std;

bool D[31][31][31][436];
int N, K;
char s[31];

bool go(int i, int a, int b, int p) {
	if (i == N) {
		if (p == K) {
			return true;
		}
		else {
			return false;
		}
	}
	if (D[i][a][b][p]) return false;
	D[i][a][b][p] = true;
	s[i] = 'A';
	if (go(i + 1, a + 1, b, p)) {
		return true;
	}
	s[i] = 'B';
	if (go(i + 1, a, b + 1, p + a)) {
		return true;
	}
	s[i] = 'C';
	if (go(i + 1, a, b, p + a + b)) {
		return true;
	}
	return false;
}
int main() {
	cin >> N >> K;
	if (go(0, 0, 0, 0)) {
		cout << s << '\n';
	}
	else {
		cout << "-1\n";
	}
	return 0;
}
