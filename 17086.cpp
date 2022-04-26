#include <iostream>
#include <queue>
using namespace std;

int N, M;
int A[51][51];
int dx[] = { 0, 1, 0, -1, -1, 1, 1, -1 };
int dy[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int d[51][51];

int go(int x, int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			d[i][j] = -1;
		}
	}
	queue<pair<int, int>>q;
	q.push(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (d[nx][ny] != -1) continue;
				if (A[nx][ny] == 1) {
					return d[xx][yy] + 1;
				}
				else {
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[xx][yy] + 1;
				}
			}
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	int ans = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 0) {
				int temp = go(i, j);
				if (ans == -1 || temp > ans) {
					ans = temp;
				}
			}
		}
	}
	cout << ans << '\n';
}