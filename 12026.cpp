#include <iostream>
#include <vector>
using namespace std;

char prev(char a) {
	if (a == 'B') {
		return 'J';
	}
	else if (a == 'O') {
		return 'B';
	}
	else {
		return 'O';
	}
}

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> D(n, -1);
	D[0] = 0;
	for (int i = 1; i < n; i++) {
		char now = s[i];
		char pre = prev(now);
		for (int j = 0; j < i; j++) {
			if (D[j] == -1) continue;
			if (s[j] != pre) continue;
			int cost = D[j] + (i - j) * (i - j);
			if (D[i] == -1 || D[i] > cost) {
				D[i] = cost;
			}
		}
	}
	cout << D[n - 1] << '\n';
}