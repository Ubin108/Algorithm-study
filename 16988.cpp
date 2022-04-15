#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

int A[21][21];
bool check[21][21];
int N, M;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int go() {
	memset(check, false, sizeof(check));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 2 && check[i][j] == false) {
				queue<pair<int, int>> q;
				int len = 0;
				bool dead = true;
				q.push(make_pair(i, j));
				check[i][j] = true;
				while (!q.empty()) {
					int x, y;
					len++;
					tie(x, y) = q.front();
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
							if (A[nx][ny] == 0) {
								dead = false;
							}
							else if(A[nx][ny] == 2 && check[nx][ny] == false){
								q.push(make_pair(nx, ny));
								check[nx][ny] = true;
							}
						}
					}
				}
				if (dead) {
					ans += len;
				}
			}
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	int maxx = -1;
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			if (A[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < N; x2++) {
				for (int y2 = 0; y2 < M; y2++) {
					if (A[x2][y2] != 0) continue;
					if (x1 == x2 && y1 == y2) continue;
					A[x1][y1] = 1;
					A[x2][y2] = 1;
					int temp = go();
					if (maxx == -1 || temp > maxx) {
						maxx = temp;
					}
					A[x1][y1] = 0;
					A[x2][y2] = 0;
				}
			}
		}
	}
	cout << maxx << '\n';
	return 0;
}