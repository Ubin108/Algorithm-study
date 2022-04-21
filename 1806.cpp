#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, S;
	cin >> N >> S;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int left = 0, right = 0;
	long long sum = A[0];
	int ans = 0;
	while (left <= right && right < N) {
		if (sum < S) {
			right++;
			if (right >= N) break;
			sum += A[right];
		}
		else if (sum == S) {
			int temp = right - left + 1;
			if (ans == 0 || ans > temp) {
				ans = temp;
			}
			right++;
			if (right >= N) break;
			sum += A[right];
		}
		else {
			int temp = right - left + 1;
			if (ans == 0 || ans > temp) {
				ans = temp;
			}
			sum -= A[left];
			left++;
			if (left > right && left < N) {
				right = left;
				sum = A[left];
			}
		}
	}
	cout << ans << '\n';
}