#include<iostream>
using namespace std;
const int K = 1e5 + 1;
#define mod 1000000007
#define int long long
int n, k;
int a[101];
int dp[101][K] {};


//Computations : n*k*3
int Candies() {


	//Edge Case: dp[1][j] : Number of ways to distribute j candies amoung 1 child.

	for (int j = 0; j <= k; j++) {

		if (j <= a[1]) {
			dp[1][j] = 1;
		} else {
			dp[1][j] = 0;
		}
	}


	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {

			if (j == 0) {
				dp[i][j] = (dp[i - 1][j] % mod);
			} else {

				int Part1 = dp[i][j - 1] % mod;
				int Part2 = dp[i - 1][j] % mod;

				int Part3 = 0;

				if ((j - a[i] - 1) >= 0) {
					Part3 = dp[i - 1][j - a[i] - 1] % mod;
				}

				dp[i][j] = (Part1 + Part2 - Part3) % mod;
			}
		}
	}


	return dp[n][k];

}






int32_t main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	cout << Candies() << endl;


}