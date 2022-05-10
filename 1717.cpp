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
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
		urank[i] = 0;
	}
	while (m--) {
		int p, q, r;
		cin >> p >> q >> r;
		if (p == 0) {
			Union(q, r);
		}
		else {
			q = Find(q);
			r = Find(r);
			if (q == r) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	return 0;
}