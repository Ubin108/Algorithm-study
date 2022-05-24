#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int D[61][61][61];

int go(int x, int y, int z) {
	if (x < 0) return go(0, y, z);
	if (y < 0) return go(x, 0, z);
	if (z < 0) return go(x, y, 0);
	if (x == 0 && y == 0 && z == 0) return 0;
	int &ans = D[x][y][z];
	if (ans != -1) return ans;
	ans = 10000000;
	vector<int>p = { 9, 3, 1 };
	do {
		int temp = go(x - p[0], y - p[1], z - p[2]);
		if (ans > temp) {
			ans = temp;
		}
	} while (next_permutation(p.begin(), p.end()));
	ans++;
	return ans;
}

int main() {	
	cin >> N;
	memset(D, -1, sizeof(D));
	int SCV[3] = { 0, 0, 0 };
	for (int i = 0; i < N; i++) {
		cin >> SCV[i];
	}
	cout << go(SCV[0], SCV[1], SCV[2]) << '\n';
	return 0;
}