#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int>pi(m);
	pi[0] = 0;
	int j = 0;
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = j + 1;
			j++;
		}
		else {
			pi[i] = 0;
		}
	}
	return pi;
}

int main() {
	string p;
	cin >> p;
	reverse(p.begin(), p.end());
	string a;
	int ans = 0;
	for (char s : p) {
		a = s + a;
		vector<int>next = preprocessing(a);
		for (int i = 0; i < next.size(); i++) {
			if (next[i] > ans) {
				ans = next[i];
			}
		}
	}
	cout << ans << '\n';
}