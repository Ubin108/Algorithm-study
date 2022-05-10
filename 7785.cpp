#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> s;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string name, state;
		cin >> name >> state;
		if (state == "enter") {
			s.insert(name);
		}
		else {
			s.erase(s.find(name));
		}
	}
	for (auto p = s.rbegin(); p != s.rend(); p++) {
		cout << *p << '\n';
	}
	return 0;
}