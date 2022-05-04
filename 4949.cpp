#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

int main() {
	while (1) {
		string s;
		getline(cin, s);
		if (s == ".") {
			break;
		}
		stack<char>A;
		bool flag = false;
		for (char c : s) {
			if (c == '(' || c == '[') {
				A.push(c);
			}
			else if (c == ')') {
				if (!A.empty() && A.top() == '(') {
					A.pop();
				}
				else {
					cout << "no\n";
					flag = true;
					break;
				}
			}
			else if (c == ']') {
				if (!A.empty() && A.top() == '[') {
					A.pop();
				}
				else {
					cout << "no\n";
					flag = true;
					break;
				}
			}
		}
		if (!flag) {
			if (A.empty()) {
				cout << "yes\n";
			}
			else {
				cout << "no\n";
			}
		}
	}
	return 0;
}