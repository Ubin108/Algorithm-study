#include <iostream>
#include <tuple>
#include <string>
#include <vector>
using namespace std;

bool check[101][101];

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	vector<tuple<int, int, int>> ans;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '*') {
				int len = 0;
				for (int k = 1; ; k++) {
					if (i + k < N && i - k >= 0 && j + k < M && j - k >= 0) {
						if (A[i][j - k] == '*' && A[i][j + k] == '*' && A[i + k][j] == '*' && A[i - k][j] == '*') {
							len = k;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
				}
				if (len > 0) {
					check[i][j] = true;
					ans.push_back(make_tuple(i, j, len));
					for (int p = 1; p <= len; p++) {
						check[i][j - p] = true;
						check[i][j + p] = true;
						check[i - p][j] = true;
						check[i + p][j] = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] == '*' && check[i][j] == false) {
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto &q: ans) {
		int i, j, len;
		tie(i, j, len) = q;
		cout << i + 1 << ' ' << j + 1 << ' ' << len << '\n';
	}
	return 0;
}