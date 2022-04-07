#include<iostream>
using namespace std;

int N, L, R, X; 
int A[15];
bool check[15];
int go(int index) {
	if (index == N) {
		int cnt = 0;
		int sum = 0;
		int maxx = -1;
		int minn = -1;
		for (int i = 0; i < N; i++) {
			if (check[i]) {
				sum += A[i];
				cnt++;
				if (maxx == -1 || maxx < A[i]) maxx = A[i];
				if (minn == -1 || minn > A[i]) minn = A[i];
			}
		}
		if (sum < L || sum > R) {
			return 0;
		}
		if (maxx - minn >= X && cnt >= 2) {
			return 1;
		}
		return 0;
	}
	check[index] = true;
	int cnt1 = go(index + 1);
	check[index] = false;
	int cnt2 = go(index + 1);
	return cnt1 + cnt2;
}

int main() {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cout << go(0) << '\n';
}