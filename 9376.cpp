#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

vector<vector<int>> bfs(vector<string>&a, int x, int y) {
	int n = a.size();
	int m = a[0].size();
	vector<vector<int>> d(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			d[i][j] = -1;
		}
	}
	deque<pair<int,int>> q;
	q.push_back(make_pair(x, y));
	d[x][y] = 0;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop_front();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
				if (d[nx][ny] == -1 && a[nx][ny] != '*') {
					if (a[nx][ny] == '#') {
						d[nx][ny] = d[x][y] + 1;
						q.push_back(make_pair(nx, ny));
					}
					else {
						d[nx][ny] = d[x][y];
						q.push_front(make_pair(nx, ny));
					}
				}
			}
		}
	}
	return d;
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int h, w;
		cin >> h >> w;
		vector<string> a(h + 2);
		for (int i = 1; i <= h; i++) {
			cin >> a[i];
			a[i] = '.' + a[i] + '.';
		}
		for (int i = 0; i <= w + 1; i++) {
			a[0] += '.';
			a[h + 1] += '.';
		}
		vector<vector<int>> d1 = bfs(a, 0, 0);
		/*
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				cout << d1[i][j] << ' ';
			}
			cout << '\n';
		}
		*/
		int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				if (a[i][j] == '$') {
					if (x1 == -1 && y1 == -1) {
						x1 = i;
						y1 = j;
					}
					else {
						x2 = i;
						y2 = j;
					}
				}
			}
		}
		vector<vector<int>> d2 = bfs(a, x1, y1);
		vector<vector<int>> d3 = bfs(a, x2, y2);
		int ans = -1;
		int temp;
		for (int i = 0; i <= h + 1; i++) {
			for (int j = 0; j <= w + 1; j++) {
				if (a[i][j] == '*') continue;
				if (d1[i][j] == -1 || d2[i][j] == -1 || d3[i][j] == -1) continue;
				temp = d1[i][j] + d2[i][j] + d3[i][j];
				if (a[i][j] == '#') temp -= 2;
				if (ans == -1 || temp < ans) {
					ans = temp;
				}
			}
		}
		cout << ans << '\n';
	}
}