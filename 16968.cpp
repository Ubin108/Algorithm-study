#include <iostream>
#include <string>
using namespace std;

int go(string &s, int index, char last) {
	if (index == s.length()) {
		return 1;
	}

	char start = (s[index] == 'c' ? 'a' : '0');
	char end = (s[index] == 'c' ? 'z' : '9');
	int ans = 0;
	for (char i = start; i <= end; i++) {
		if (i != last) {
			ans += go(s, index + 1, i);
		}
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << go(s, 0, ' ') << '\n';
	return 0;
}