#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A[51][51];
int d[51][51];
int rsize[2501];

int dx[] = { 0, -1, 0, 1 };
int dy[] = { -1, 0, 1, 0 };

int go(int x, int y, int num) {
	queue<pair<int,int>>q;
	q.push(make_pair(x, y));
	int cnt = 0;
	d[x][y] = num;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			if (A[xx][yy] & (1 << i)) continue;
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
				if (d[nx][ny] == 0) {
					q.push(make_pair(nx, ny));
					d[nx][ny] = num;
				}
			}
		}
	}
	return cnt;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	int room = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] == 0) {
				room++;
				rsize[room] = go(i, j, room);
			}
		}
	}
	cout << room << '\n';
	int maxx = 0;
	for (int i = 1; i <= room; i++) {
		if (maxx < rsize[i]) {
			maxx = rsize[i];
		}
	}
	cout << maxx << '\n';

	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				if (A[i][j] & (1 << k)) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (d[i][j] == d[nx][ny]) continue;
					if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
						int sum = rsize[d[i][j]] + rsize[d[nx][ny]];
						if (sum > ans) {
							ans = sum;
						}
					}
				}
			}
		}
	}
	cout << ans << '\n';
}