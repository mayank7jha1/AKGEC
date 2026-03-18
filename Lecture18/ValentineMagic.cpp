#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
int n, m;
const int N = 5001;
int b[N] {}, g[N] {};
int dp[N][N] {};


/*
	dp[i][j] = F(i,j) : Maximum sum by choosing boys from i to n-1 and j to m-1.

*/

int F(int i, int j) {

	if (i == n) {

		//F(n,j) : 0.
		return 0;
	}

	if (j == m) {
		//THis is not a valid path.
		return 1e8;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}


	//I choose the current girl to make pair with the current boy.
	int Op1 = abs(b[i] - g[j]) + F(i + 1, j + 1);

	//I skip the current girl;
	int Op2 = 0 + F(i, j + 1);

	return dp[i][j] = min(Op1, Op2);

}




int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> g[i];
	}

	sort(b, b + n);
	sort(g, g + m);

	memset(dp, -1, sizeof(dp));
	cout << F(0, 0) << endl;

}