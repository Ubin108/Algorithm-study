#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int w, h;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
vector<vector<int>> go(vector<string>&a, int x, int y) {
	vector<vector<int>> dis(h, vector<int>(w, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	dis[x][y] = 0;
	while (!q.empty()) {
		int xx = q.front().first;
		int yy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = xx + dx[i];
			int ny = yy + dy[i];
			if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
				if (dis[nx][ny] == -1 && a[nx][ny] != 'x') {
					dis[nx][ny] = dis[xx][yy] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return dis;
}

int main() {
	while (1) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		vector<string> A(h);
		for (int i = 0; i < h; i++) {
			cin >> A[i];
		}
		vector<pair<int, int>>pos(1);
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (A[i][j] == 'o') {
					pos[0] = make_pair(i, j);
				}
				else if (A[i][j] == '*') {
					pos.push_back(make_pair(i, j));
				}
			}
		}
		int num = pos.size();
		bool flag = true;
		vector<vector<int>> d(num, vector<int>(num));
		for (int i = 0; i < num; i++) {
			auto dist = go(A, pos[i].first, pos[i].second);
			for (int j = 0; j < num; j++) {
				d[i][j] = dist[pos[j].first][pos[j].second];
				if (d[i][j] == -1) {
					flag = false;
				}
			}
		}
		if (!flag) {
			cout << "-1\n";
			continue;
		}
		vector<int>list;
		int ans = -1;
		for (int i = 1; i < num; i++) {
			list.push_back(i);
		}
		do {
			int sum = d[0][list[0]];
			for (int i = 0; i < num - 2; i++) {
				sum += d[list[i]][list[i+1]];
			}
			if (ans == -1 || sum < ans) {
				ans = sum;
			}
		} while (next_permutation(list.begin(), list.end()));
		cout << ans << '\n';
	}
}