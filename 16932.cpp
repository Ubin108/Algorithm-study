#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001][1001];
int group[1001][1001];
int gsize[1001];
int num = 1;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 1 && group[i][j] == 0) {
				q.push(make_pair(i, j));
				group[i][j] = num;
				gsize[num]++;
				while (!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
							if (A[nx][ny] == 1 && group[nx][ny] == 0) {
								group[nx][ny] = num;
								gsize[num]++;
								q.push(make_pair(nx, ny));
							}
						}
					}
				}
				num++;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == 0) {
				vector<int>list;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 0 && nx < N&&ny >= 0 && ny < M) {
						if (group[nx][ny] != 0) {
							list.push_back(group[nx][ny]);
						}
					}
				}
				sort(list.begin(), list.end());
				list.erase(unique(list.begin(), list.end()), list.end());
				int sum = 0;
				for (int p : list) {
					sum += gsize[p];
				}
				if (sum > ans) {
					ans = sum;
				}
			}
		}
	}
	cout << ans + 1 << '\n';
}