#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

long long cal(long long x) {
	return x * (x + 1) / 2;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n + 1);
	vector<int> lg(n + 1, 0);
	vector<int> rg(n + 1, n + 1);
	vector<int> ls(n + 1, 0);
	vector<int> rs(n + 1, n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}
	{
		stack<pair<int, int>> sg, ss;
		sg.push(make_pair(1, A[1]));
		ss.push(make_pair(1, A[1]));
		for (int i = 2; i <= n; i++) {
			while (!sg.empty() && A[i] >= sg.top().second) {
				rg[sg.top().first] = i;
				sg.pop();
			}
			sg.push(make_pair(i, A[i]));
			while (!ss.empty() && A[i] <= ss.top().second) {
				rs[ss.top().first] = i;
				ss.pop();
			}
			ss.push(make_pair(i, A[i]));
		}
	}
	{
		stack<pair<int, int>> sg, ss;
		sg.push(make_pair(n, A[n]));
		ss.push(make_pair(n, A[n]));
		for (int i = n - 1; i >= 1; i--) {
			while (!sg.empty() && A[i] > sg.top().second) {
				lg[sg.top().first] = i;
				sg.pop();
			}
			sg.push(make_pair(i, A[i]));
			while (!ss.empty() && A[i] < ss.top().second) {
				ls[ss.top().first] = i;
				ss.pop();
			}
			ss.push(make_pair(i, A[i]));
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = min(i, lg[i] + 1);
		int right = max(i, rg[i] - 1);
		long long len = right - left + 1;
		ans += (cal(len) - cal(right - i) - cal(i - left)) * A[i];
	}
	for (int i = 1; i <= n; i++) {
		int left = min(i, ls[i] + 1);
		int right = max(i, rs[i] - 1);
		long long len = right - left + 1;
		ans -= (cal(len) - cal(right - i) - cal(i - left)) * A[i];
	}
	cout << ans << '\n';
	return 0;
}
