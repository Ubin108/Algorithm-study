#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> preprocessing(string p) {
	int m = p.size();
	vector<int> pi(m);
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
	int n;
	cin >> n;
	string p;
	cin >> p;
	vector<int>next = preprocessing(p);
	cout << n - next[n - 1] << '\n';
	return 0;
}
