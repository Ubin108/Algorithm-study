#include <iostream>
#include <cstring>
using namespace std;

int D[10001];
int V[101];

int main() {
	memset(D, 0, sizeof(D));
	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> V[i];
	}
	D[0] = 1;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - V[i] >= 0) {
				D[j] += D[j - V[i]];
			}
		}
	}
	cout << D[K] << '\n';
	return 0;
}