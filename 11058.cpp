#include <iostream>
using namespace std;

long long D[101];

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= 100; i++) {
		D[i] = D[i - 1] + 1;
		for (int j = 3; i - j > 0; j++) {
			long long temp = D[i - j] * (j - 1);
			if (D[i] < temp) {
				D[i] = temp;
			}
		}
	}
	cout << D[N] << '\n';
}