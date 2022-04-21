#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	int left = 0, right = 0;
	int sum = A[0];
	int ans = 0;
	while (left <= right && right < N) {
		if (sum < M) {
			right++;
			if (right >= N) break;
			sum += A[right];
		}
		else if (sum == M) {
			ans++;
			right++;
			if (right >= N) break;
			sum += A[right];
		}
		else {
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