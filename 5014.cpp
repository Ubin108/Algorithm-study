#include <iostream>
#include <queue>
using namespace std;

int F, S, G, U, D;
bool check[1000001];
int num[1000001] = { 0, };

int main() {
	cin >> F >> S >> G >> U >> D;
	queue<int> q;
	q.push(S);
	check[S] = true;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		if (temp + U <= F && check[temp + U] == false) {
			q.push(temp + U);
			check[temp + U] = true;
			num[temp + U] = num[temp] + 1;
		}
		if (temp - D >= 1 && check[temp - D] == false) {
			q.push(temp - D);
			check[temp - D] = true;
			num[temp - D] = num[temp] + 1;
		}
	}
	if (check[G]) {
		cout << num[G] << '\n';
	}
	else {
		cout << "use the stairs\n";
	}
	return 0;
}