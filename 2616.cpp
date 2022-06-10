#include <iostream>
#include <algorithm>
using namespace std;

int D[50001][4];
int A[50001];
int K[50001];
int N, M;

int sum(int x, int y) {
	return K[y] - K[x - 1];
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		K[i] = K[i - 1] + A[i];
	}
	cin >> M;
	for (int j = 1; j <= 3; j++) {
		for (int i = j * M; i <= N; i++) {
			D[i][j] = D[i - 1][j];
			D[i][j] = max(D[i][j], D[i - M][j - 1] + sum(i - M + 1, i));
		}
	}
	cout << D[N][3] << '\n';
}