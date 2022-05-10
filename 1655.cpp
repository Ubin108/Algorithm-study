#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

int main() {
	priority_queue<int> left;
	priority_queue<int, vector<int>, greater<int>> right;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int item;
		cin >> item;
		if (left.empty() || right.empty()) {
			left.push(item);
		}
		else {
			if (item <= left.top()) {
				left.push(item);
			}
			else if (item >= right.top()) {
				right.push(item);
			}
			else {
				left.push(item);
			}
		}
		while (!((left.size() - right.size() == 1) || (left.size() - right.size() == 0))) {
			if (left.size() > right.size()) {
				right.push(left.top());
				left.pop();
			}
			else {
				left.push(right.top());
				right.pop();
			}
		}
		cout << left.top() << '\n';
	}
}