#include <iostream>
using namespace std;

int N;
int A[401][801];
int S[401][801];
int ans;

void go(int row, int left, int right, int sum) {
	if (row < 1 || row > N) return;
	if (left < 1 || right > 2 * row - 1) return;
	sum += (S[row][right] - S[row][left-1]);
	if (sum > ans) {
		ans = sum;
	}
	if (left % 2 == 1) {
		go(row + 1, left, right + 2, sum);
	}
	else {
		go(row - 1, left - 2, right, sum);
	}
}

int main() {
	for (int t = 1; ; t++) {
		ans = -400000;
		cin >> N;
		if (N == 0) {
			break;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				cin >> A[i][j];
				S[i][j] = S[i][j - 1] + A[i][j];
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= 2 * i - 1; j++) {
				go(i, j, j, 0);
			}
		}
		cout << t << ". " << ans << '\n';
	}
	return 0;
}