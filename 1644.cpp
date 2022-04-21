#include <iostream>
#include <vector>
using namespace std;

bool prime[4000001];
int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= 4000000; i++) {
		for (int j = 2; i * j <= 4000000; j++) {
			prime[i*j] = true;
		}
	}
	vector<int>num;
	for (int i = 2; i <= 4000000; i++) {
		if (!prime[i]) {
			num.emplace_back(i);
		}
	}
	int size = num.size();

	int left = 0, right = 0;
	int sum = num[0];
	int ans = 0;
	while (left <= right && right < size) {
		if (sum < N) {
			right++;
			if (right >= size) break;
			sum += num[right];
		}
		else if (sum == N) {
			ans++;
			right++;
			if (right >= size) break;
			sum += num[right];
		}
		else {
			sum -= num[left];
			left++;
			if (left > right && left < size) {
				right = left;
				sum = num[left];
			}
		}
	}
	cout << ans << '\n';
}