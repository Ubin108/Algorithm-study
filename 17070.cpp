#include <iostream>
#include <vector>
using namespace std;

int N;
int A[17][17];

int go(int x, int y, int dir) {
	if (x == N - 1 && y == N - 1) {
		return 1;
	}
	int ans = 0;
	if (dir == 0) {
		if (y + 1 < N && A[x][y + 1] != 1) {
			ans += go(x, y + 1, 0);
		}
		if (x + 1 < N && y + 1 < N && A[x + 1][y] != 1 && A[x + 1][y + 1] != 1 && A[x][y + 1] != 1) {
			ans += go(x + 1, y + 1, 1);
		}
	}
	if (dir == 1) {
		if (y + 1 < N && A[x][y + 1] != 1) {
			ans += go(x, y + 1, 0);
		}
		if (x + 1 < N && y + 1 < N && A[x + 1][y] != 1 && A[x + 1][y + 1] != 1 && A[x][y + 1] != 1) {
			ans += go(x + 1, y + 1, 1);
		}
		if (x + 1 < N && A[x + 1][y] != 1) {
			ans += go(x + 1, y, 2);
		}
	}
	if (dir == 2) {
		if (x + 1 < N && y + 1 < N && A[x + 1][y] != 1 && A[x + 1][y + 1] != 1 && A[x][y + 1] != 1) {
			ans += go(x + 1, y + 1, 1);
		}
		if (x + 1 < N && A[x + 1][y] != 1) {
			ans += go(x + 1, y, 2);
		}
	}
	return ans;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	cout << go(0, 1, 0) << '\n';
	return 0;
}