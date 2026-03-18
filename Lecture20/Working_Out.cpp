#include<iostream>
#include<algorithm>
using namespace std;

/*
	dp1[x][y]: Maximum calorie from 1,1 to x,y.
	dp2[x][y]: Maximum calorie n,1 to x,y.
	dp3[x][y]: maximum Calorie from x,y to n,m.
	dp4[x][y]: Maximum Calorie from x,y to 1,m.

*/

const int N = 1e3 + 10;
int dp1[N][N] {};
int dp2[N][N] {};
int dp3[N][N] {};
int dp4[N][N] {};

int n, m;
int calorie[N][N] {};

int main() {

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> calorie[i][j];
		}
	}


	//Dp1[i][j] : max(dp[i-1][j],dp[i][j-1])+calorie[i][j]
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (i == 1 and j == 1) {
				dp1[i][j] = calorie[i][j];
				continue;
			} else if (i == 1) {
				dp1[i][j] = dp1[i][j - 1] + calorie[i][j];
			} else if (j == 1) {
				dp1[i][j] = dp1[i - 1][j] + calorie[i][j];
			} else {
				dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]) + calorie[i][j];
			}
		}
	}

	//Dp2 :
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {

			if (i == n and j == 1) {
				dp2[i][j] = calorie[i][j];
				continue;
			} else if (i == n) {
				dp2[i][j] = dp2[i][j - 1] + calorie[i][j];
			} else if (j == 1) {
				dp2[i][j] = dp2[i + 1][j] + calorie[i][j];
			} else {
				dp2[i][j] = max(dp2[i + 1][j], dp2[i][j - 1]) + calorie[i][j];
			}
		}
	}

	//Dp3 :
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {

			if (i == n and j == m) {
				dp3[i][j] = calorie[i][j];
				continue;
			} else if (i == n) {
				dp3[i][j] = dp3[i][j + 1] + calorie[i][j];
			} else if (j == m) {
				dp3[i][j] = dp3[i + 1][j] + calorie[i][j];
			} else {
				dp3[i][j] = max(dp3[i + 1][j], dp3[i][j + 1]) + calorie[i][j];
			}
		}
	}


	//Dp4 :
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {

			if (i == 1 and j == m) {
				dp4[i][j] = calorie[i][j];
				continue;
			} else if (i == 1) {
				dp4[i][j] = dp4[i][j + 1] + calorie[i][j];
			} else if (j == m) {
				dp4[i][j] = dp4[i - 1][j] + calorie[i][j];
			} else {
				dp4[i][j] = max(dp4[i - 1][j], dp4[i][j + 1]) + calorie[i][j];
			}
		}
	}


	//Since We cannot be sure about the meeting point preassume
	//every box as the meeting point and across all the meeting
	//points find that results in max. calorie.
	//Ensure that they only meet once.


	int ans = 0;

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 2; j <= m - 1; j++) {

			//Current Box  : i,j : Potential Meeting Point.
			//To ensure they meet only once.
			//There are only two ways to reach this box.

			int op1 = dp1[i - 1][j] + dp3[i + 1][j] + dp2[i][j - 1] + dp4[i][j + 1];
			int op2 = dp1[i][j - 1] + dp3[i][j + 1] + dp2[i + 1][j] + dp4[i - 1][j];

			int final = max(op1, op2);
			ans = max(ans, final);
		}
	}

	cout << ans << endl;

}




// |

// _

// | (i + 1, j) ---- > max calorie to n, m.



// _ (i, j) _

