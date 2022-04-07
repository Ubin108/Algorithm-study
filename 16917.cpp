#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;
	int res = A * X + B * Y;
	int temp = 0;
	for (int i = 0; i <= 100000; i++) {
		temp = 2 * i * C + max(0, X - i) * A + max(0, Y - i)*B;
		res = min(res, temp);
	}
	cout << res << '\n';
}
	