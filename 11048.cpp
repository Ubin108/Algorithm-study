#include <iostream>
#include <algorithm>
using namespace std;

int A[1001][1001];
int d[1001][1001];

int max3(int x, int y, int z) {
	return max(max(x, y), z);
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
			d[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			d[i][j] = max3(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + A[i][j];
		}
	}
	cout << d[N][M] << '\n';
}