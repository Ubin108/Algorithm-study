#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N, M;
int S[11];
int D[5001][5001];

int go(int x, int y) {
	if (x > N) {
		return 0;
	}
	int &ans = D[x][y];
	if (ans != -1) {
		return 0;
	}
	ans = 1;
	for (int i = 0; i < M; i++) {
		int num = x + y + S[i];
		int score = y + S[i];
		go(num, score);
	}
	return 0;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> S[i];
		}
		memset(D, -1, sizeof(D));
		go(0, 0);
		int ans = -1;
		for (int i = 1; i <= N; i++) {
			if (D[N][i] == 1) {
				ans = i;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}