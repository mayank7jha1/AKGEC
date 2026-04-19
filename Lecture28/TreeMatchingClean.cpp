#include<iostream>
#include<vector>
using namespace std;
vector<int>tree[200001];
int dp[200001][2];

/*
	dp[node][0] : Maximum Matching when node is not part of any matching.
	dp[node][1] : Maximum Matching when node is part of any matching.

*/


void Solve(int node, int parent) {

	dp[node][0] = 0;
	dp[node][1] = 0;

	//Exclude :
	for (auto child : tree[node]) {
		if (child != parent) {
			Solve(child, node);
			dp[node][0] += (max(dp[child][0], dp[child][1]));
		}
	}


	//Include :
	for (auto child : tree[node]) {
		if (child != parent) {

			int Op1 = 1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1]);

			dp[node][1] = max(dp[node][1], Op1);
		}
	}

}




int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	Solve(1, 0);
	cout << max(dp[1][0], dp[1][1]) << endl;

}