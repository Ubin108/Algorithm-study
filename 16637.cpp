#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Term {
	int num;
	int oper;
};

int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	int maxx = 0;
	vector<Term> A(N);
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			A[i] = { s[i] - '0',0 };
		}
		else {
			int op = 1;
			if (s[i] == '-') op = 2;
			else if (s[i] == '*') op = 3;
			A[i] = { 0, op };
		}
	}
	int M = (N - 1) / 2;
	for (int i = 0; i < (1 << M); i++) {
		bool check = true;
		for (int j = 0; j < M - 1; j++) {
			if ((i&(1 << j)) > 0 && (i&(1 << (j + 1))) > 0) {
				check = false;
			}
		}
		if (!check) continue;
		vector<Term> B(A);
		for (int j = 0; j < M; j++) {
			if ((i&(1 << j)) > 0) {
				if (A[2 * j + 1].oper == 1) {
					B[2 * j].num += B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
				}
				else if (A[2 * j + 1].oper == 2) {
					B[2 * j].num -= B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
					B[2 * j + 1].oper = 1;
				}
				else if (A[2 * j + 1].oper == 3) {
					B[2 * j].num *= B[2 * j + 2].num;
					B[2 * j + 2].num = 0;
					B[2 * j + 1].oper = 1;
				}				
			}
		}
		int res = B[0].num;
		for (int j = 0; j < M; j++) {
			if (B[2 * j + 1].oper == 1) {
				res += B[2 * j + 2].num;
			}
			else if (B[2 * j + 1].oper == 2) {
				res -= B[2 * j + 2].num;
			}
			else if (B[2 * j + 1].oper == 3) {
				res *= B[2 * j + 2].num;
			}
		}
		if (i == 0) {
			maxx = res;
		}
		if (res > maxx) {
			maxx = res;
		}
	}
	cout << maxx << '\n';
	return 0;
}