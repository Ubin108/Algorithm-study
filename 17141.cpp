#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M; 
int A[51][51];
int d[51][51];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int ans = -1;
vector<pair<int, int>> pos;

void bfs() {
	memset(d, -1, sizeof(d));
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == 3) {
				d[i][j] = 0;
				q.push(make_pair(i, j));
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
	bool flag = true;
	int temp = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] != 1) {
				if (d[i][j] == -1) {
					flag = false;
				}
				else {
					if (d[i][j] > temp) {
						temp = d[i][j];
					}
				}
			}
		}
	}
	if (flag) {
		if (ans == -1 || ans > temp) {
			ans = temp;
		}
	}
}

void go(int idx, int cnt) {
	if (idx == pos.size()) {
		if (cnt == M) {
			bfs();
		}
		return;
	}
	int x = pos[idx].first;
	int y = pos[idx].second;
	A[x][y] = 3;
	go(idx + 1, cnt + 1);
	A[x][y] = 0;
	go(idx + 1, cnt);
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 2) {
				A[i][j] = 0;
				pos.push_back(make_pair(i, j));
			}
		}
	}
	go(0, 0);
	cout << ans << '\n';
}