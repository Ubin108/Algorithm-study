#include <iostream>
#include <queue>
using namespace std;

bool check[201][201];
bool ans[201];
int from[] = { 0, 0 , 1, 1, 2, 2 };
int to[] = { 1, 2, 0, 2, 0, 1 };
int cap[3];
int sum;

int main() {	
	for (int i = 0; i < 3; i++) {
		cin >> cap[i];
	}
	sum = cap[2];
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	check[0][sum] = true;
	while (!q.empty()) {
		int cur[3];
		cur[0] = q.front().first;
		cur[1] = q.front().second;
		cur[2] = sum - cur[0] - cur[1];
		q.pop();
		for (int i = 0; i < 6; i++) {
			int next[3] = { cur[0], cur[1], cur[2] };
			next[to[i]] += next[from[i]];
			int temp = next[to[i]] - cap[to[i]];
			if (temp > 0) {
				next[from[i]] = temp;
				next[to[i]] = cap[to[i]];
			}
			else {
				next[from[i]] = 0;
				if (from[i] == 0) {
					ans[next[2]] = true;
				}
			}
			if (!check[next[0]][next[2]]) {
				check[next[0]][next[2]] = true;
				q.push(make_pair(next[0], next[1]));
			}
		}
	}
	for (int i = 0; i <= cap[2]; i++) {
		if (ans[i]) {
			cout << i << ' ';
		}
	}
	cout << '\n';
	return 0;
}