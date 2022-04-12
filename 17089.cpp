#include <iostream>
using namespace std;

bool a[4001][4001];
int deg[4001];

int main() {
	int N, M;
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		a[x - 1][y - 1] = a[y - 1][x - 1] = true;
		deg[x - 1]++;
		deg[y - 1]++;
	}
	int minn = -1;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i][j]) {
				for (int k = j + 1; k < N; k++) {
					if (a[i][k] && a[j][k]) {
						int res = deg[i] + deg[j] + deg[k] - 6;
						if (minn == -1 || res < minn) {
							minn = res;
						}
					}
				}
			}
		}
		
	}
	cout << minn << '\n';
	return 0;
}