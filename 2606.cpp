#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000001];
int urank[1000001];

int Find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (urank[x] < urank[y]) swap(x, y);
	parent[y] = x;
	if (urank[x] == urank[y]) {
		urank[x] = urank[y] + 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		urank[i] = 0;
	}
	while (m--) {
		int p, q;
		cin >> p >> q;
		Union(p, q);
	}
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (Find(i) == 1) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}