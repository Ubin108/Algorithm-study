#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int A[501];
int D[501][501];

int go(int x, int y) {
	if (x == y) return 0;
	if (D[x][y] != -1) return D[x][y];
	int sum = 0;
	int &ans = D[x][y];
	for (int i = x; i <= y; i++) {
		sum += A[i];
	}
	for (int k = x; k < y; k++) {
		int temp = go(x, k) + go(k + 1, y) + sum;
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		int K;
		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> A[i];
		}
		memset(D, -1, sizeof(D));
		cout << go(0, K - 1) << '\n';
	}
	return 0;
}