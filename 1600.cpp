#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int dx[] = { 0, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2 };
int dy[] = { 1, 0, -1, 0, 1, 2, 2, 1, -1, -2, -2, -1 };
int cost[] = { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 };
int A[201][201];
int d[201][201][31];

int main() {
	int K, W, H;
	cin >> K >> W >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> A[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	queue<tuple<int, int,int>> q;
	q.push(make_tuple(0, 0, 0));
	d[0][0][0] = 0;
	while (!q.empty()) {
		int x, y, t;
		tie(x, y, t) = q.front();
		q.pop();
		for (int i = 0; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nt = t + cost[i];
			if (nx >= 0 && nx < H &&ny >= 0 && ny < W) {
				if (A[nx][ny] == 1) continue;
				if (nt <= K) {
					if (d[nx][ny][nt] == -1) {
						q.push(make_tuple(nx, ny, nt));
						d[nx][ny][nt] = d[x][y][t] + 1;
					}
				}	
			}
		}
	}
	int ans = -1;
	for (int i = 0; i <= K; i++) {
		if (d[H - 1][W - 1][i] == -1) continue;
		if (ans == -1 || ans > d[H - 1][W - 1][i]) {
			ans = d[H - 1][W - 1][i];
		}
	}
	cout << ans << '\n';
	return 0;
}