#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;



class Solution {


	int dp[51][51][202];
	vector<vector<int>>graph;
	int n;

	int dfs(int m, int c, int turn) {

		//Base Condition:
		if (turn >= 2 * n) {
			return 0;
		}

		if (m == 0) {
			return 1;
		}

		if (c == m) {
			return 2;
		}

		if (dp[m][c][turn] != -1) {
			return dp[m][c][turn];
		}



		//Mouse's Turn :
		if (turn % 2 == 0) {
			bool draw = 0;

			for (auto next_m : graph[m]) {
				int val = dfs(next_m, c, turn + 1);

				//Main next_m par gaya mujhe ek rasta mil gya jisme mouse
				//jeet raha hain toh m jispar mouse abhi khada hain
				//vo bhi 1 hogya na.

				if (val == 1) {
					return dp[m][c][turn] = 1;
				}

				if (val == 0) {
					//Hold :
					draw = 1;
				}
			}

			if (draw == 1) {
				return dp[m][c][turn] = 0;
			} else {
				return dp[m][c][turn] = 2;//Cat wins.
			}


		} else {
			bool draw = 0;

			for (auto next_c : graph[c]) {
				if (next_c == 0) {
					continue;
				}

				int val = dfs(m, next_c, turn + 1);

				if (val == 2) {
					return dp[m][c][turn] = 2;
				}

				if (val == 0) {
					draw = 1;
				}
			}

			if (draw == 1) {
				return dp[m][c][turn] = 0;
			} else {
				return dp[m][c][turn] = 1;//Mouse wins.
			}
		}
	}
public:
	int catMouseGame(vector<vector<int>>& graph) {
		this->graph = graph;
		this->n = graph.size();

		memset(dp, -1, sizeof(dp));


		//At the start of the game  : mouse is at 1, cat is at 2 and Turn is 0.
		return dfs(1, 2, 0);
	}
};




int main() {



}