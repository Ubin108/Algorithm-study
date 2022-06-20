#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int D[301][301];

int go(int x, int y) {
	if (x == 1 && y == 1) {
		return 0;
	}
	int &ans = D[x][y];
	if (ans != -1) {
		return ans;
	}
	ans = 90000;
	for (int i = 1; i <= x; i++) {
		ans = min(ans, go(i, y) + go(x - i, y) + 1);
	}
	for (int i = 1; i <= y; i++) {
		ans = min(ans, go(x, i) + go(x, y - i) + 1);
	}
	return ans;
}

int main() {
	int N, M;
	cin >> N >> M;
	memset(D, -1, sizeof(D));
	D[1][1] = 0;
	cout << go(N, M) << '\n';
	return 0;
}