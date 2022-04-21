#include <iostream>
#include <algorithm>
using namespace std;
int go(long long A, long long B) {
	if (A == B) return 1;
	if (A > B) return -1;
	int t1 = go(2 * A, B);
	int t2 = go(10 * A + 1, B);
	if (t1 == -1 && t2 == -1) return -1;
	if (t1 == -1) return t2 + 1;
	if (t2 == -1) return t1 + 1;
	return min(t1, t2) + 1;
}

int main() {
	long long A, B;
	cin >> A >> B;
	cout << go(A, B) << '\n';
	return 0;
}
