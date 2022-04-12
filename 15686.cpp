#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> a(N, vector<int>(N));
	vector<pair<int, int>> home;
	vector<pair<int, int>> chicken;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				home.emplace_back(make_pair(i, j));
			}
			else if (a[i][j] == 2) {
				chicken.emplace_back(make_pair(i, j));
			}
		}
	}
	vector<int> b(chicken.size());
	for (int i = 0; i < M; i++) {
		b[i] = 1;
	}
	sort(b.begin(), b.end());

	int ans = -1;
	do {
		int sum = 0;
		for (auto &h : home) {
			vector<int> dists;
			for (int i = 0; i < b.size(); i++) {
				if (b[i] == 0) continue;
				auto &c = chicken[i];
				int d1 = c.first - h.first;
				int d2 = c.second - h.second;
				int dist = abs(d1) + abs(d2);
				dists.push_back(dist);
			}
			sum += *min_element(dists.begin(), dists.end());
		}
		if (ans == -1 || sum < ans) {
			ans = sum;
		}

	} while (next_permutation(b.begin(), b.end()));
	
	cout << ans << '\n';
}