#include <iostream>
#include <cstring>
using namespace std;

long long D[101][21];
long long A[101];

int main() {
	int N;
	cin >> N;
	memset(D, 0, sizeof(D));
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	D[1][A[1]] = 1;
	for (int i = 2; i <= N - 1; i++) {
		for (int j = 0; j <= 20; j++) {
			if (D[i - 1][j] != 0) {
				int temp = j;
				if (temp + A[i] >= 0 && temp + A[i] <= 20) {
					D[i][temp + A[i]] += D[i - 1][j];
				}
				if (temp - A[i] >= 0 && temp - A[i] <= 20) {
					D[i][temp - A[i]] += D[i - 1][j];
				}
			}
		}
	}
	cout << D[N - 1][A[N]] << '\n';
}