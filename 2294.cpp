#include <iostream>
#include <cstring>
#include <algorithm>
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - V[i] >= 0) {
				if (D[j] != 0) {
					D[j] = min(D[j], D[j - V[i]] + 1);
				}
				else {
					D[j] = D[j - V[i]] + 1;
				}
			
			}
		}
	}
	if (D[K] == 0) {
		D[K] = -1;
	}
	cout << D[K] << '\n';
	return 0;
}