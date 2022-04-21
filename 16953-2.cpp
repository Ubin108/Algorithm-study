#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long A, B;
	int flag = 1;
	cin >> A >> B;
	for (int i = 0; A <= B; i++) {
		if (A == B) {
			cout << i + 1 << "\n";
			flag = 0;
		}
		if (B % 2 == 0) {
			B /= 2;
		}
		else if (B % 10 == 1) {
			B = (B - 1) / 10;
		}
	}
	if (flag == 1) {
		cout << "-1\n";
	}
	return 0;
}