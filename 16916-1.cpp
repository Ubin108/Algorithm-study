#include <iostream>
#include <string>
using namespace std;

long long mod = 2147483647; //큰 소수 사용하기
int base = 256;
long long h(string s) {
	long long ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % mod; //라빈카프 알고리즘
	}
	return ans;
}
int go(string &s, string &p) {
	int n = s.length();
	int m = p.length();
	if (n < m) return 0;
	long long hash_p = h(p);
	long long hash_s = h(s.substr(0, m));
	long long first = 1;
	for (int i = 0; i < m - 1; i++) {
		first = (first * base) % mod;
	}
	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) {
			if (s.substr(i, m) == p) return 1;
		}
		if (i + m < n) { //이전 해쉬함수값으로 다음 해쉬함수값 구하기
			hash_s = hash_s - (s[i]*first)%mod;
			hash_s = (hash_s + mod) % mod;
			hash_s = ((hash_s * base) % mod + s[i + m]) % mod;
		}
	}
	return 0;
}
int main() {
	string s, p;
	cin >> s >> p;
	cout << go(s, p) << '\n';
	return 0;
}
