#include <iostream>
#include <stack>
using namespace std;

int T;
long long A[100001];

int main() {
	while (1) {
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		stack<long long> s;
		for (int i = 0; i < N; i++) {
			int left = i;
			while (!s.empty() && A[s.top()] > A[i]) {
				long long height = A[s.top()];
				s.pop();
				long long width = i;
				if (!s.empty()) {
					width = i - s.top() - 1;
				}
				if (ans < height * width) {
					ans = height * width;
				}
			}
			s.push(i);
		}
		while (!s.empty()) {
			long long height = A[s.top()];
			s.pop();
			long long width = N;
			if (!s.empty()) {
				width = N - s.top() - 1;
			}
			if (ans < height * width) {
				ans = height * width;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}