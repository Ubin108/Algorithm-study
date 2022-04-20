#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int> &M) {
	int temp = M[0] + M[1] + M[2];
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += M[i * 3 + j];
		}
		if (sum != temp) {
			return false;
		}
	}
	for (int i = 0; i < 3; i++) {
		int sum = 0;
		for (int j = 0; j < 3; j++) {
			sum += M[i + j * 3];
		}
		if (sum != temp) {
			return false;
		}
	}
	if (temp != M[0] + M[4] + M[8]) return false;
	if (temp != M[2] + M[4] + M[6]) return false;
	return true;
}

int go(vector<int> &A, vector<int> &M) {
	int ans = 0;
	for (int i = 0; i < 9; i++) {
		ans += abs(A[i] - M[i]);
	}
	return ans;
}

int main() {
	vector<int> A(9);
	vector<int> M(9);
	int minn = -1;
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
	}
	for (int i = 1; i <= 9; i++) {
		M[i - 1] = i;
	}
	do {
		if (check(M)) {
			int diff = go(A, M);
			if (minn == -1 || diff < minn) {
				minn = diff;
			}
		}
	} while (next_permutation(M.begin(), M.end()));
	cout << minn << '\n';
	return 0;
}