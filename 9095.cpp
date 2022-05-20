#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		int nums[] = { 1, 2, 3 };
		int d[12] = { 0, };
		d[0] = 1;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				if (i - nums[j] >= 0) {
					d[i] += d[i - nums[j]];
				}
			}
		}
		cout << d[n] << '\n';
	}
}