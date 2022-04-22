#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N), C(N), D(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	vector<int> First, Second;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			First.push_back(A[i] + B[j]);
			Second.push_back(C[i] + D[j]);
		}
	}
	sort(First.begin(), First.end());
	sort(Second.begin(), Second.end());
	long long ans = 0;
	for (int i = 0; i < First.size(); i++) {
		long long x = First[i];
		auto p = equal_range(Second.begin(), Second.end(), -x);
		ans += p.second - p.first;
	}
	cout << ans << '\n';
}