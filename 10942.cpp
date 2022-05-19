#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int A[2001];
int D[2001][2001];

int go(int x, int y) {
	if (x == y) return 1;
	else if (x + 1 == y) {
		if (A[x] == A[y]) return 1;
		else return 0;
	}
	if (D[x][y] != -1) return D[x][y];
	if (A[x] == A[y]) {
		return D[x][y] = go(x + 1, y - 1);
	}
	else {
		return D[x][y] = 0;
	}
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	memset(D, -1, sizeof(D));

	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		cout << go(x - 1, y - 1) << '\n';
	}
	return 0;
}