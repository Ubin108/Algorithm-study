#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N + 1);
	vector<int> d(N + 1, -1);
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	d[1] = 0;
	for (int i = 1; i <= N - 1; i++) {
		if (d[i] == -1) continue;
		for (int j = 1; j <= A[i]; j++) {
			if (i + j > N) break;
			if (d[i + j] == -1 || d[i + j] > d[i] + 1) {
				d[i + j] = d[i] + 1;
			}
		}
	}
	cout << d[N] << '\n';
	return 0;
}