#include <iostream>
#include <array>
#include <string>
#include <map>
#include <queue>
using namespace std;

int main() {
	array<string, 3> s;
	int n;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		if (n > 0) {
			cin >> s[i];
		}
		else {
			s[i] = "";
		}
	}
	int cnt[3] = { 0,0,0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cnt[s[i][j] - 'A']++;
		}
	}
	array<string, 3> ans;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			ans[i] += (char)('A' + i);
		}
	}
	map<array<string, 3>, int> d;
	queue<array<string, 3>> q;
	q.push(s);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			if (p[i].size() == 0) continue;
			for (int j = 0; j < 3; j++) {
				if (i == j) continue;
				array<string, 3> next(p);
				next[j].push_back(next[i].back());
				next[i].pop_back();
				if (d[next] == 0) {
					d[next] = d[p] + 1;
					q.push(next);
				}
			}
		}
	}
	cout << d[ans] << '\n';
	return 0;
}