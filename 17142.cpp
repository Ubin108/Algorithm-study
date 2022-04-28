#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int A[51][51];
int d[51][51];
int N, M;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
vector<pair<int, int>> pos;
int ans = -1;

void bfs() {
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 3) {
				q.push(make_pair(i, j));
				d[i][j] = 0;
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (A[nx][ny] != 1 && d[nx][ny] == -1) {
					d[nx][ny] = d[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	int cur = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 0) {
				if (d[i][j] == -1) {
					return;
				}
				else {
					if (cur < d[i][j]) {
						cur = d[i][j];
					}
				}
			}
		}
	}
	if (ans == -1 || cur < ans) {
		ans = cur;
	}
}

void go(int idx, int cnt) {
	if (idx == pos.size()) {
		if (cnt == M) {
			bfs();
		}
	}
	else {
		int x = pos[idx].first;
		int y = pos[idx].second;
		A[x][y] = 3;
		go(idx + 1, cnt + 1);
		A[x][y] = 2;
		go(idx + 1, cnt);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				pos.push_back(make_pair(i, j));
			}
		}
	}
	go(0, 0);
	cout << ans << '\n';
	return 0;
}