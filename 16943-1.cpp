#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string A;
	int B;
	cin >> A >> B;
	sort(A.begin(), A.end());
	int maxx = -1;
	do {
		if (A[0] == '0') continue;
		int num = stoi(A);
		if (num < B && num > maxx) {
			maxx = num;
		}
	} while (next_permutation(A.begin(), A.end()));
	cout << maxx << '\n';
	return 0;
}