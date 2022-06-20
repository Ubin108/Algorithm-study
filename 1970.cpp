#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int A[1001];
int D[1001][1001];

int go(int x, int y) {
	if (x >= y) {
		return 0;
	}
	int &ans = D[x][y];
	if (ans != -1) {
		return ans;
	}
	ans = 0;
	for (int i = x + 1; i <= y; i++) {
		if (A[x] == A[i]) {
			ans = max(ans, go(x + 1, i - 1) + go(i + 1, y) + 1);
		}
	}
	if (ans == 0) {
		ans = go(x + 1, y);
	}
	return ans;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	memset(D, -1, sizeof(D));
	cout << go(1, N) << '\n';
	return 0;
}