#include <iostream>
#include <cstring>
using namespace std;

int N, M;
long long D[21][21];

long long fact(int x) {
	long long num = 1;
	while (x >= 1) {
		num *= x;
		x--;
	}
	return num;
}

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}


long long go(int x, int y) {
	if (x == 0 || y == 0) {
		return 0;
	}
	if (x == 1) {
		return 1;
	}
	long long &ans = D[x][y];
	if (ans != -1) {
		return ans;
	}
	ans = go(x - 1, y - 1) + (x - 1) * go(x - 1, y); // 제 1종 스털링 수(원소의 개수가 x인 집합을 구분되지 않는 y개의 원순열로 분할하는 방법의 수)
	return ans;
}

int main() {
	cin >> N >> M;
	memset(D, -1, sizeof(D));
	D[1][1] = 1;
	long long temp = go(N, M);
	long long whole = fact(N);
	long long g = gcd(temp, whole);
	cout << temp / g << "/" << whole / g << '\n';
	return 0;
}
