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


	for (auto child : tree[node]) {
		if (child != parent) {
			Solve(child, node);
			/*
				When You are here: I have the matching for the child node.
				Option Exclude: Where no matching is in node i.e. current node does not participate in any matching.
			*/
			dp[node][0] += (max(dp[child][0], dp[child][1]));
		}
	}


	/*
		For the current node I have the answer for exclude option.
		and It is stored in dp[node][0].

		Now Evaluate the answer for Option Include:
	*/

	for (auto child : tree[node]) {
		if (child != parent) {
			/*
				Current node is making a matching with this current child.
				Matching Edge : (node,child)

				int Op1 = 1 + dp[child][0] + Matching of Rest of the Subtree of current node.

				dp[node][0] : Matching of All the Subtrees of current node.

				Matching of Rest of the subtree of the current node = dp[node][0]-Matching of (current child).

			*/

			int Op1 = 1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1]);

			//Option 1: Is the answer when you take edge with the current child.
			//dp[node][1] : Maximum of all the options.
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