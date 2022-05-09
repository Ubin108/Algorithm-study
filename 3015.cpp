#include <iostream>
#include <stack>
using namespace std;

long long A[500001];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	stack<long long> s;
	stack<long long> p;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		int h = A[i];
		int cnt = 1;
		while (!s.empty()) {
			if (s.top() <= A[i]) {
				ans += p.top();
				if (s.top() == A[i]) {
					cnt += p.top();
				}
				s.pop();
				p.pop();
			}
			else {
				break;
			}
		}
		if (!s.empty()) {
			ans++;
		}
		s.push(h);
		p.push(cnt);
	}
	cout << ans << '\n';
	return 0;
}