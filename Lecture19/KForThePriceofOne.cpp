#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int t;
int n, p, k;
int cost[N] {};
int dp[N] {};

int Solve() {

	//dp[i] : Min Cost to buy items till i index.

	for (int i = 1; i <= n; i++) {
		if (i < k) {
			dp[i] = dp[i - 1] + cost[i];
		} else if (i == k) {
			dp[i] = cost[i];
		} else {
			dp[i] = dp[i - k] + cost[i];
		}
	}


	//What is the maximum item i can buy.
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		if (dp[i] <= p) {
			//I can buy items till i.
			ans = i;
		}
	}

	return ans;
}



int main() {
	cin >> t;
	while (t--) {
		cin >> n >> p >> k;
		for (int i = 1; i <= n; i++) {
			cin >> cost[i];
		}

		sort(cost, cost + n);

		cout << Solve() << endl;

	}


}