#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[10];
int b;
int n;
int maxx = -1;
bool check[10];

int go(int index, int num) {
	if (index == n) {
		return num;
	}
	for (int i = 0; i < n; i++) {
		if (check[a[i]]) continue;
		if (index == 0 && a[i] == 0) continue;

		check[a[i]] = true;
		int temp = go(index + 1, num * 10 + a[i]);
		if (temp < b && temp > maxx) {
			maxx = temp;
		}
		check[a[i]] = false;
	}
	return maxx;
}

int main() {
	string num;
	cin >> num;
	n = num.size();
	for (int i = 0; i < n; i++) {
		a[i] = num[i] - '0';
	}
	cin >> b;
	cout << go(0, 0) << '\n';

	return 0;
}