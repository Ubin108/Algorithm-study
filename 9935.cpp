#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool check[1000001];
int main() {
	string s, p;
	cin >> s;
	cin >> p;
	int n = s.size();
	int m = p.size();
	if (m == 1) {
		for (int i = 0; i < n; i++) {
			if (s[i] == p[0]) {
				check[i] = true;
			}
		}
	}
	else {
		stack<pair<int,int>> a;
		for (int i = 0; i < n; i++) {
			if (s[i] == p[0]) {
				a.push(make_pair(i, 0));
			}
			else {
				if(!a.empty()) {
					auto k = a.top();
					if (s[i] == p[k.second + 1]) {
						a.push(make_pair(i, k.second + 1));
						if (k.second + 1 == m - 1) {
							for (int j = 0; j < m; j++) {
								auto t = a.top();
								check[t.first] = true;
								a.pop();
							}
						}
					}
					else {
						while (!a.empty()) {
							a.pop();
						}
					}
				}
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		flag = true;
		cout << s[i];
	}
	if (!flag) {
		cout << "FRULA";
	}
	cout << '\n';
	return 0;
}