#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int H, W, N;
	cin >> H >> W;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i];
	}
	int maxx = 0;
	for (int i = 0; i < N; i++) {
		int r1 = A[i], c1 = B[i];
		for(int j = i + 1; j < N; j++) {
			int r2 = A[j], c2 = B[j];
			for (int rot1 = 0; rot1 < 2; rot1++) {
				for (int rot2 = 0; rot2 < 2; rot2++) {
					if (r1 + r2 <= H && max(c1,c2) <= W) {
						int res = r1 * c1 + r2 * c2;
						if (res > maxx) {
							maxx = res;
						}
					}
					if (c1 + c2 <= W && max(r1, r2) <= H) {
						int res = r1 * c1 + r2 * c2;
						if (res > maxx) {
							maxx = res;
						}
					}
				}
				swap(r2, c2);
			}
			swap(r1, c1);
		}
	}
	cout << maxx << '\n';
}