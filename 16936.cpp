#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, long long>>A(N);
	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		A[i].second = num;
		for (int j = 0; ; j++) {
			if (num % 3 == 0) {
				num /= 3;
			}
			else {
				A[i].first = -j;
				break;
			}
		}
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		cout<< A[i].second << ' ';
	}
	cout << '\n';
	return 0;
}