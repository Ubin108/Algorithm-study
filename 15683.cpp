#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int N, M;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

void check(vector<vector<int>> &a, vector<vector<int>> &b, int x, int y, int dir) {
	int i = x;
	int j = y;
	while (i >= 0 && i < N && j >= 0 && j < M) {
		if (a[i][j] == 6) break;
		b[i][j] = a[x][y];
		i += dx[dir];
		j += dy[dir];
	}
}

int go(vector<vector<int>> &a, vector<tuple<int,int,int>> &cctv, int index, vector<int> dirs) {
	if (index == cctv.size()) {
		int x, y, cc;
		vector<vector<int>> b(a);
		for (int i = 0; i < cctv.size(); i++) {
			tie(x, y, cc) = cctv[i];
			if (cc == 1) {
				check(a, b, x, y, dirs[i]);
			}
			else if (cc == 2) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (cc == 3) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
			}
			else if (cc == 4) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
			}
			else if (cc == 5) {
				check(a, b, x, y, dirs[i]);
				check(a, b, x, y, (dirs[i] + 1) % 4);
				check(a, b, x, y, (dirs[i] + 2) % 4);
				check(a, b, x, y, (dirs[i] + 3) % 4);
			}
		}
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (b[i][j] == 0) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	int ans = 64;
	for (int i = 0; i < 4; i++) {
		dirs[index] = i;
		int temp = go(a, cctv, index + 1, dirs);
		if (temp < ans) {
			ans = temp;
		}
	}
	return ans;
}

int main() {
	cin >> N >> M;
	vector<vector<int>> a(N, vector<int>(M));
	vector<tuple<int, int, int>> cctv;
	vector<int> dirs;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j] > 0 && a[i][j] < 6) {
				cctv.emplace_back(i, j, a[i][j]);
				dirs.push_back(0);
			}
		}
	}
	cout << go(a, cctv, 0, dirs) << '\n';
}