#include <iostream>
#include <set>
using namespace std;

set<int> res;
int a[5][5];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void go(int x, int y, int num, int idx) {
	if (idx == 6) {
		res.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
			go(nx, ny, num * 10 + a[nx][ny], idx + 1);
		}
	}
}

int main() {

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(i, j, a[i][j], 1);
		}
	}
	cout << res.size() << '\n';
}