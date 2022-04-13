#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

void go(vector<vector<int>> &A, tuple<int,int,int> &rot) {
	int r, c, s;
	tie(r, c, s) = rot;
	vector<vector<int>> group;
	for (int i = 0; i < s; i++) {
		vector<int> num;
		for (int x = r - (s - i), y = c - (s - i); y < c + (s - i); y++) {
			num.push_back(A[x][y]);
		}
		for (int x = r - (s - i), y = c + (s - i); x < r + (s - i); x++) {
			num.push_back(A[x][y]);
		}
		for (int x = r + (s - i), y = c + (s - i); y > c - (s - i); y--) {
			num.push_back(A[x][y]);
		}
		for (int x = r + (s - i), y = c - (s - i); x > r - (s - i); x--) {
			num.push_back(A[x][y]);
		}
		group.push_back(num);
	}
	for (int i = 0; i < s; i++) {
		auto &num = group[i];
		int idx = 0;
		rotate(num.rbegin(), num.rbegin() + 1, num.rend());
		for (int x = r - (s - i), y = c - (s - i); y < c + (s - i); y++) {
			A[x][y] = num[idx++];
		}
		for (int x = r - (s - i), y = c + (s - i); x < r + (s - i); x++) {
			A[x][y] = num[idx++];
		}
		for (int x = r + (s - i), y = c + (s - i); y > c - (s - i); y--) {
			A[x][y] = num[idx++];
		}
		for (int x = r + (s - i), y = c - (s - i); x > r - (s - i); x--) {
			A[x][y] = num[idx++];
		}
	}
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> A(N, vector<int>(M));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	int r, c, s;
	vector<tuple<int, int, int>> rot(K);
	for (int i = 0; i < K; i++) {
		cin >> r >> c >> s;
		rot[i] = make_tuple(r - 1, c - 1, s);
	}
	sort(rot.begin(), rot.end());
	
	int ans = -1;
	do {
		auto B = A;
		for (auto &t : rot) {
			go(B, t);
		}
		int minn = -1;
		for (int i = 0; i < N; i++) {
			int sum = 0;
			for (int j = 0; j < M; j++) {
				sum += B[i][j];
			}
			if (minn == -1 || sum < minn) {
				minn = sum;
			}
		}
		if (ans == -1 || minn < ans) {
			ans = minn;
		}
	} while (next_permutation(rot.begin(), rot.end()));
	cout << ans << '\n';
}