#include <iostream>
#include <cstring>
using namespace std;

char l[300001];
char r[300001];
char A[31];
char rA[31];
int n;
int ln = 0, rn = 0;

bool check(int dir) {
	char *st= l;
	int len = ln;
	char *comp = rA;
	if (dir == 1) {
		st = r;
		len = rn;
		comp = A;
	}
	if (len < n) {
		return false;
	}
	for (int i = 0; i < n; i++) {
		if (st[len - i - 1] != comp[i]) {
			return false;
		}
	}
	if (dir == 0) {
		ln -= n;
	}
	else {
		rn -= n;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A;
	n = strlen(A);
	for (int i = 0; i < n; i++) {
		rA[i] = A[n - i - 1];
	}
	char T[300001];
	cin >> T;
	int dir = 0;
	int left = 0;
	int right = strlen(T) - 1;
	while (left <= right) {
		if (dir == 0) {
			l[ln++] = T[left++];
		}
		else {
			r[rn++] = T[right--];
		}
		if (check(dir)) {
			dir = 1 - dir;
		}
	}
	for (int i = ln - 1; i >= 0; i--) {
		r[rn++] = l[i];
		check(1);
	}
	for (int i = rn-1; i >= 0; i--) {
		cout << r[i];
	}
	cout << '\n';
	return 0;
}