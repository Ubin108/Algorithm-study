#include <iostream>
using namespace std;

int N, M;
char a[31][31];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

bool check(int x, int y){
	return (x >= 0 && x < N && y >= 0 && y < M);
}

int go(int x, int y, int cnt) {
	int minn = -1;
	if (cnt == 0) {
		return 0;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		while(check(nx, ny) && a[nx][ny] == '.'){
			a[nx][ny] = '#';
			cnt--;
			nx += dx[i];
			ny += dy[i];
		}
		nx -= dx[i];
		ny -= dy[i];
		if (!(x == nx && y == ny)) {
			int temp = go(nx, ny, cnt);
			if (temp != -1) {
				if (minn == -1 || temp + 1 < minn) {
					minn = temp + 1;
				}
			}
		}
		while (!(x == nx && y == ny)) {
			a[nx][ny] = '.';
			cnt++;
			nx -= dx[i];
			ny -= dy[i];
		}
	}
	return minn;
}

int main() {
	int t = 1;
	while (cin >> N >> M) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
			for(int j = 0; j < M; j++) {
				if (a[i][j] == '.') {
					cnt++;
				}
			}
		}
		int ans = -1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == '.') {
					a[i][j] = '#';
					int temp = go(i, j, cnt - 1);
					if (temp != -1) {
						if (ans == -1 || temp < ans) {
							ans = temp;
						}
					}
					a[i][j] = '.';
				}
				
			}
		}
		cout << "Case " << t++ << ": " << ans << '\n';
	}
	return 0;
}