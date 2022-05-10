#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> s;
	set<string> ans;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string name;
		cin >> name;
		s.insert(name);
	}
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;
		if (s.count(name)) {
			ans.insert(name);
		}
	}
	cout << ans.size() << '\n';
	for (auto p : ans) {
		cout << p << '\n';
	}
	return 0;
}