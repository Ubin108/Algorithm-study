#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		vector<int>A(N);
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}
		if (N == 1) {
			cout << "1\n";
			continue;
		}
		queue<pair<int,int>>q;
		queue<int>dq;
		for (int i = 0; i < N; i++) {
			q.push(make_pair(i,A[i]));
		}
		sort(A.begin(), A.end());
		for (int i = N - 1; i >= 0; i--) {
			dq.push(A[i]);
		}
		int ans = 0;
		int cnt = 1;
		while (!q.empty()) {
			auto x = q.front();
			if (x.second == dq.front()) {
				if (q.front().first == M) {
					ans = cnt;
				}
				dq.pop();
				q.pop();
				cnt++;
			}
			else {
				q.pop();
				q.push(x);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
