#include <iostream>
using namespace std;
bool a[201][201];
int main() {
	int N, M;
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		a[x - 1][y - 1] = true;
		a[y - 1][x - 1] = true;
	}
	int cnt = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				if (a[i][j] || a[i][k] || a[j][k]) {
					continue;
				}
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}