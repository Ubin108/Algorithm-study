#include <iostream>
using namespace std;

int A[101][101];
int D[101][101];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	D[1][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == N && j == N) {
				break;
			}
			if (i + A[i][j] <= N) {
				D[i + A[i][j]][j] += D[i][j];
			}
			if (j + A[i][j] <= N) {
				D[i][j + A[i][j]] += D[i][j];
			}
		}
	}
	cout << D[N][N] << '\n';
}