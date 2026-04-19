#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int catMouseGame(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<vector<vector<int>>>dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
		vector<vector<vector<int>>>outdegree(n, vector<vector<int>>(n, vector<int>(2, 0)));

		//This is for traversal and finding the values of dp at all the nodes.
		queue <tuple<int, int, int>>q;


		//1. Calculate the Out-degrees of all the nodes.
		for (int m = 0; m < n; m++) {
			for (int c = 0; c < n; c++) {
				outdegree[m][c][0] = graph[m].size();
				outdegree[m][c][1] = graph[c].size();

				//if the turn is of cat you cannot go to zero.
				for (auto nbr : graph[c]) {
					if (nbr == 0) {
						outdegree[m][c][1]--;
					}
				}
			}
		}



		//2. Add the terminal nodes whose answer you already know to queue :
		for (int c = 1; c < n; c++) {
			for (int turn = 0; turn < 2; turn++) {

				dp[0][c][turn] = 1; //Mouse wins
				q.push({0, c, turn});


				dp[c][c][turn] = 2;//Cat wins
				q.push({c, c, turn});
			}
		}



		//Reverse Topological sort :
		while (!q.empty()) {
			auto [m, c, turn] = q.front();
			q.pop();

			int ans = dp[m][c][turn];


			//Current Turn is of Mouse :
			if (turn == 0) {

				int prev_turn = 1;
				for (auto nbr : graph[c]) {
					if (nbr == 0) {
						continue;
					}

					if (dp[m][nbr][prev_turn] == 0) {
						//Ye State is undefined :
						if (ans == 2) {
							dp[m][nbr][turn] = 2;
							q.push({m, nbr, turn});
						} else if (ans == 1) {
							outdegree[m][nbr][prev_turn]--;
							if (outdegree[m][nbr][prev_turn] == 0) {
								dp[m][nbr][prev_turn] = 1;
								q.push({m, nbr, prev_turn});
							}
						}
					}

				}

			} else {

				//Current turn is of Cat :

				int prev_turn = 0;
				for (auto nbr : graph[m]) {
					if (dp[nbr][c][turn] == 0) {
						if (ans == 1) {
							dp[nbr][c][prev_turn] = 1;
							q.push({nbr, c, prev_turn});
						} else if (ans == 2) {
							outdegree[nbr][c][prev_turn]--;
							if (outdegree[nbr][c][prev_turn] == 0) {
								q.push({nbr, c, prev_turn});
							}
						}
					}
				}
			}
		}

	}
};





int main() {



}