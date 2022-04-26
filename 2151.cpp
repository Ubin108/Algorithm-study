#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };

int main() {
	int N;
	cin >> N;
	vector<string>A(N);
	vector<vector<int>> list(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<pair<int, int>>mir;
	int start = -1, end = -1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i][j] == '#') {
				mir.push_back(make_pair(i, j));
				if (start == -1) {
					start = mir.size() - 1;
				}
				else {
					end = mir.size() - 1;
				}
				list[i][j] = mir.size() - 1;
			}
			else if (A[i][j] == '!') {
				mir.push_back(make_pair(i, j));
				list[i][j] = mir.size() - 1;
			}
		}
	}
	int num = mir.size();
	vector<vector<bool>>check(num, vector<bool>(num, false));
	for (int i = 0; i < num; i++) {
		for (int k = 0; k < 4; k++) {
			int nx = mir[i].first + dx[k];
			int ny = mir[i].second + dy[k];
			while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
				if (A[nx][ny] == '*') break;
				if (A[nx][ny] == '!' || A[nx][ny] == '#') {
					check[i][list[nx][ny]] = true;
				}
				nx += dx[k];
				ny += dy[k];
			}
		}
	}
	queue<int> q;
	vector<int> dist(num, -1);
	q.push(start);
	dist[start] = 0;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < num; i++) {
			if (x == i) continue;
			if (check[x][i] && dist[i] == -1) {
				dist[i] = dist[x] + 1;
				q.push(i);
			}
		}
	}
	cout << dist[end] - 1 << '\n';
	return 0;
}