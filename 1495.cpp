#include <iostream>
#include <algorithm>
using namespace std;

int N, S, M;
int V[51];
int D[51][1001];

int main() {
	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}
	D[0][S] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= M; j++) {
			if (D[i][j] != 0) {
				if (j + V[i] <= M) {
					D[i + 1][j + V[i]] = 1;
				}
				if (j - V[i] >= 0) {
					D[i + 1][j - V[i]] = 1;
				}
			}
		}
	}
	int flag = 0;
	for (int i = M; i >= 0; i--) {
		if (D[N][i] == 1) {
			cout << i << '\n';
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "-1\n";
	}
	return 0;
}