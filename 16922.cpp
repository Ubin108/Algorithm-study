#include <iostream>
using namespace std;

bool check[50 * 20 + 1];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N - i; j++) {
			for (int k = 0; k <= N - i - j; k++) {
				int p = N - i - j - k;
				int num = i * 1 + j * 5 + k * 10 + p * 50;
				check[num] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < 50 * 20 + 1; i++) {
		if (check[i]) {
			cnt++;
		}
	}
	cout << cnt << '\n';
}