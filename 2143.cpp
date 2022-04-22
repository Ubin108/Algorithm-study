#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int T, N, M;
	cin >> T;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> M;
	vector<int> B(M);
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}

	vector<int> First;
	vector<int> Second;
	
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			First.push_back(sum);
		}
	}
	for (int i = 0; i < M; i++) {
		int sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			Second.push_back(sum);
		}
	}
	sort(First.begin(), First.end());
	sort(Second.begin(), Second.end());
	int ans = 0;
	for (int i = 0; i < First.size(); i++) {
		int x = First[i];
		auto p = equal_range(Second.begin(), Second.end(), T - x);
		int n = p.second - p.first;
		ans += n;
	}
	cout << ans << '\n';
}