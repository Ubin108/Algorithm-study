#include <iostream>
using namespace std;

int N; 
int S[10];
int W[10];

int go(int idx) {
	if (idx == N) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (S[i] <= 0) cnt++;
		}
		return cnt;
	}

	int flag = 0;
	if (S[idx] <= 0) {
		return go(idx + 1);
	}
	int maxx = -1;
	for (int i = 0; i < N; i++) {
		if (i == idx) continue;
		if (S[i] <= 0) continue;
		flag = 1;
		S[idx] -= W[i];
		S[i] -= W[idx];
		int temp = go(idx + 1);
		if (maxx == -1 || temp > maxx) {
			maxx = temp;
		}
		S[idx] += W[i];
		S[i] += W[idx];
	}
	if (flag == 0) {
		return go(idx + 1);
	}
	return maxx;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> W[i];
	}
	cout << go(0) << '\n';
	return 0;
}