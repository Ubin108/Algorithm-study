#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> T(1500001);
	vector<int> P(1500001);
	vector<int> D(1500001);

	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		D[i + 1] = max(D[i + 1], D[i]);
		D[i + T[i]] = max(D[i + T[i]], D[i] + P[i]);
	}
	cout << D[N + 1] << '\n';
	return 0;
}