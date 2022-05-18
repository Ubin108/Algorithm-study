#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Trie {
	struct Node {
		int children[26];
		bool valid;
		Node() {
			for (int i = 0; i < 26; i++) {
				children[i] = -1;
			}
			valid = false;
		}
	};
	vector<Node> trie;
	int root;
	int init() {
		Node x;
		trie.push_back(x);
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}
	void add(int node, string &s, int index) {
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[index] - 'a';
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}
		int child = trie[node].children[c];
		add(child, s, index + 1);
	}
	void add(string &s) {
		add(root, s, 0);
	}
	bool search(int node, string &s, int index) {
		if (node == -1) return false;
		if (index == s.length()) return trie[node].valid;
		int c = s[index] - 'a';
		int child = trie[node].children[c];
		return search(child, s, index + 1);
	}
	bool search(string &s) {
		return search(root, s, 0);
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	Trie trie;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		trie.add(s);
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;
		if (trie.search(s)) {
			ans++;
		}
	}
	cout << ans << '\n';
	return 0;
}