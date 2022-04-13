#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Term {
	int num;
	int op;
};
int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<Term> A(N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			A[i] = { s[i] - '0', 0 };
		}
		else {
			int op = 1;
			if (s[i] == '-') op = 2;
			else if (s[i] == '*') op = 3;
			A[i] = { 0, op };
		}
	}
	int M = N / 2;
	int maxx = -2147483648;
	for (int i = 0; i < (1 << M); i++) {
		bool flag = true;
		for (int j = 0; j < M - 1; j++) {
			if ((i&(1 << j)) > 0 && (i&(1 << (j+1))) > 0) {
				flag = false;
			}
		}
		if (!flag) continue;
		vector<Term> B(A);
		for (int j = 0; j < M; j++) {
			if ((i&(1 << j)) > 0) {
				if (B[2 * j + 1].op == 1) {
					B[2 * j].num += B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
					B[2 * j + 1].op = -1;
				}
				else if (B[2 * j + 1].op == 2) {
					B[2 * j].num -= B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
					B[2 * j + 1].op = -1;
				}
				else if (B[2 * j + 1].op == 2) {
					B[2 * j].num *= B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
					B[2 * j + 1].op = -1;
				}
			}
		}
		vector<Term> C;
		for (int j = 0; j < N; j++) {
			if (N % 2 == 0) {
				C.push_back(B[j]);
			}
			else {
				if (B[j].op == -1) {
					j++;
				}
				else if (B[j].op == 3) {
					int temp = C.back().num * B[j + 1].num;
					j++;
					C.pop_back();
					C.push_back({ temp, 0 });
				}
				else {
					C.push_back(B[j]);
				}
			}
		}
		int sum = C[0].num;
		for (int j = 0; j < C.size() / 2; j++) {
			if (C[2 * j + 1].op == 1) {
				sum += C[2 * j + 2].num;
			}
			if (C[2 * j + 1].op == 2) {
				sum -= C[2 * j + 2].num;
			}
		}
		if (sum > maxx) {
			maxx = sum;
		}
	}
	cout << maxx << '\n';
	return 0;
}