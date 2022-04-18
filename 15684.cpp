#include <iostream>
#include <vector>
using namespace std;

int A[11][31] = { 0, };
int N, M, H;

int check(int x, int y) {
	while (x < H) {
		if (A[x][y] == 1) {
			y++;
		}
		else if (A[x][y] == 2) {
			y--;
		}
		x++;
	}
	return y;
}

bool go() {
	for (int i = 0; i < N; i++) {
		if (check(0, i) != i) return false;
	}
	return true;
}

int main() {
	int x, y;
	vector<pair<int, int>> pos;
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		A[x - 1][y - 1] = 1;
		A[x - 1][y] = 2;
	}
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < H; j++) {
			if (A[j][i] == 0) {
				pos.emplace_back(make_pair(j, i));
			}
		}
	}
	int len = pos.size();
	int ans = -1;

	if (go()) {
		ans = 0;
		cout << "0\n";
		return 0;
	}
	for (int i = 0; i < len; i++) {
		int x1 = pos[i].first;
		int y1 = pos[i].second;
		if (A[x1][y1] != 0 || A[x1][y1 + 1] != 0) continue;
		A[x1][y1] = 1;
		A[x1][y1 + 1] = 2;
		if (go()) {
			if (ans == -1 || ans > 1) {
				ans = 1;
			}
		}
		for (int j = i + 1; j < len; j++) {
			int x2 = pos[j].first;
			int y2 = pos[j].second;
			if (A[x2][y2] != 0 || A[x2][y2 + 1] != 0) continue;
			A[x2][y2] = 1;
			A[x2][y2 + 1] = 2;
			if (go()) {
				if (ans == -1 || ans > 2) {
					ans = 2;
				}
			}
			for (int k = j + 1; k < len; k++) {
				int x3 = pos[k].first;
				int y3 = pos[k].second;
				if (A[x3][y3] != 0 || A[x3][y3 + 1] != 0) continue;
				A[x3][y3] = 1;
				A[x3][y3 + 1] = 2;
				if (go()) {
					if (ans == -1 || ans > 3) {
						ans = 3;
					}
				}
				A[x3][y3] = 0;
				A[x3][y3 + 1] = 0;
			}
			A[x2][y2] = 0;
			A[x2][y2 + 1] = 0;
		}
		A[x1][y1] = 0;
		A[x1][y1 + 1] = 0;
	}
	cout << ans << '\n';
}