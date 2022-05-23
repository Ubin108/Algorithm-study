#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101], V[101];
int D[101][100001];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W[i] >> V[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) {
				D[i][j] = max(D[i][j], D[i][j - W[i]] + V[i]);
			}
		}
	}
	cout << D[N][K] << '\n';
	return 0;
}