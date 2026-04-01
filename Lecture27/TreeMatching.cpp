#include<iostream>
#include<vector>
using namespace std;
vector<int> tree[200001];
int dp[200001][2];
// dp[node][0] = max matching when node is NOT matched to a child
// dp[node][1] = max matching when node IS matched to one child
void Solve(int node, int parent) {
	dp[node][0] = 0;
	dp[node][1] = 0;
	for (auto child : tree[node]) {
		if (child != parent) {
			Solve(child, node);
			// Exclude: each child contributes its best
			dp[node][0] += max(dp[child][0], dp[child][1]);
		}
	}
	// Include: try matching node with each child
	for (auto child : tree[node]) {
		if (child != parent) {
			// Match edge (node, child):
			//   - child contributes dp[child][0] (child is now used, can't match downward)
			//   - all OTHER children contribute their best (already summed in dp[node][0])
			//   - subtract this child's contribution from dp[node][0] and add dp[child][0]
			int candidate = 1 + dp[child][0]
			                + dp[node][0] - max(dp[child][0], dp[child][1]);
			dp[node][1] = max(dp[node][1], candidate);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	Solve(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
}
