#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

	int main() {
	int N, S;
	cin >> N >> S;
	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int M = N / 2;
	vector<int> first(1 << M);
	for (int i = 0; i < (1 << M); i++) {
		for (int j = 0; j < M; j++) {
			if (i&(1 << j)) {
				first[i] += A[j];
			}
		}
	}
	N -= M;
	vector<int> second(1 << N);
	for (int i = 0; i < (1 << N); i++) {
		for (int j = 0; j < N; j++) {
			if (i&(1 << j)) {
				second[i] += A[j + M];
			}
		}
	}
	sort(first.begin(), first.end());
	sort(second.begin(), second.end());
	reverse(second.begin(), second.end());

	int p1 = 0, p2 = 0;
	M = (1 << M);
	N = (1 << N);
	long long ans = 0;
	while (p1 < M && p2 < N) {
		int temp = first[p1] + second[p2];
		if (temp < S) {
			p1++;
		}
		else if (temp == S) {
			long long c1 = 1, c2 = 1;
			int x = first[p1];
			int y = second[p2];
			p1++;
			p2++;
			while (p1 < M && first[p1] == x) {
				c1++;
				p1++;
			}
			while (p2 < N && second[p2] == y) {
				c2++;
				p2++;
			}
			ans += c1 * c2;
		}
		else {
			p2++;
		}
	}
	if (S == 0) {
		ans--;
	}
	cout << ans << '\n';
	return 0;
}