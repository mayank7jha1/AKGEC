#include<iostream>
#include<vector>
#include<string>
using namespace std;

class DSU {
	vector<int>SP;
	vector<int>rank;
public:
	//Constructor :
	DSU(int n) {
		SP.resize(n, -1);
		rank.resize(n, -1);
	}

	//Find Function : It Fetches you the Superparent of the node.
	int FindU(int node) {
		if (SP[node] == -1) {
			return node;
		}

		//Path Compression
		return SP[node] = FindU(SP[node]);
	}

	//Union By rank/size :
	void UnionU(int x, int y) {

		int S1 = FindU(x);
		int S2 = FindU(y);

		if (S1 != S2) {
			//These x and y are not part of same component:
			if (rank[S1] < rank[S2]) {
				SP[S1] = S2;
				rank[S2] += rank[S1];
			} else {
				SP[S2] = S1;
				rank[S1] += rank[S2];
			}
		}
	}
};


int main() {

	int n;
	cin >> n;

	DSU g(26);
	bool visited[26] {false};


	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		for (int j = 0; j < s.length(); j++) {
			visited[s[j] - 'a'] = 1;

			//Union of the adjacent characters :
			if (j < s.length() - 1) {
				g.UnionU(s[j] - 'a', s[j + 1] - 'a');
			}
		}
	}

	//Number of unique superparent  : Unique passwords :
	int ans = 0;
	for (int i = 0; i < 26; i++) {
		if (visited[i] == 1 and g.FindU(i) == i) {
			ans++;
		}
	}

	cout << ans << endl;
}