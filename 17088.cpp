#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}
	if (N == 0) {
		cout << "0\n";
		return 0;
	}
	
	int ans = -1;
	for (int d1 = -1; d1 <= 1; d1++) {
		for (int d2 = -1; d2 <= 1; d2++) {
			int first = B[0] + d1;
			int second = B[1] + d2;
			bool flag = true;
			int cnt = 0;
			int diff = second - first;
			if (d1 != 0) cnt++;
			if (d2 != 0) cnt++;
			int num = first + diff;
			for (int i = 2; i < N; i++) {
				num += diff;
				if (B[i] == num) continue;
				else if (B[i] + 1 == num || B[i] - 1 == num) {
					cnt++;
					continue;
				}
				else {
					flag = false;
					break;
				}
			}
			if (flag) {
				if (ans == -1 || ans > cnt) {
					ans = cnt;
				}
			}
		}
	}
	cout << ans << '\n';
}
