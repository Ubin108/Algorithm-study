#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<string> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	int maxx = -1;
	for (int x1 = 0; x1 < N; x1++) {
		for (int y1 = 0; y1 < M; y1++) {
			for (int k1 = 0; ; k1++) {
				if (x1 - k1 < 0 || x1 + k1 >= N || y1 - k1 < 0 || y1 + k1 >= M) break;
				if (A[x1 - k1][y1] != '#' || A[x1 + k1][y1] != '#' || A[x1][y1 - k1] != '#' || A[x1][y1 + k1] != '#') break;
				A[x1 - k1][y1] = '*';
				A[x1 + k1][y1] = '*';
				A[x1][y1 - k1] = '*';
				A[x1][y1 + k1] = '*';
				for (int x2 = 0; x2 < N; x2++) {
					for (int y2 = 0; y2 < M; y2++) {
						for (int k2 = 0; ; k2++) {
							if (x2 - k2 < 0 || x2 + k2 >= N || y2 - k2 < 0 || y2 + k2 >= M) break;
							if (A[x2 - k2][y2] != '#' || A[x2 + k2][y2] != '#' || A[x2][y2 - k2] != '#' || A[x2][y2 + k2] != '#') break;
							int area = (4 * k1 + 1)*(4 * k2 + 1);
							if (maxx == -1 || area > maxx) {
								maxx = area;
							}
						}
					}
				}
			}

			for (int k1 = 0; ; k1++) {
				if (x1 - k1 < 0 || x1 + k1 >= N || y1 - k1 < 0 || y1 + k1 >= M) break;
				if (A[x1 - k1][y1] != '*' || A[x1 + k1][y1] != '*' || A[x1][y1 - k1] != '*' || A[x1][y1 + k1] != '*') break;
				A[x1 - k1][y1] = '#';
				A[x1 + k1][y1] = '#';
				A[x1][y1 - k1] = '#';
				A[x1][y1 + k1] = '#';
			}
		}
	}
	cout << maxx << '\n';
}