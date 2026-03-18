#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
int n, k;
vector<int>taste, calorie;
const int shift = 1e5;
int dp[101][2 * shift] {};

//Top Down : Recursion + Storing.

//Dp : 101*2*1e5 * constant : 2*10^7
//SC : 101*2*1e5



/*
	F(i,sum) : State ----> Dp[i][sum]


*/
int F(int i, int sum) {

	if (i == n) {
		if (sum == 0) {
			return 0;//This is a Valid Path.
		} else {
			return -1e8;//THis is an Invalid Path.
		}
	}

	//Before Calculating :
	if (dp[i][sum + shift] != -1) {
		return dp[i][sum + shift];
	}


	//Currently We are trying to solve for the state F(i,sum).

	//You are at the ith fruit.

	//When You are choosing the current fruit.
	int Op1 = taste[i] + F(i + 1, sum + (taste[i] - k * calorie[i]));


	//WHen you are not choosing the current fruit.
	int Op2 = 0 + F(i + 1, sum);

	return dp[i][sum + shift] = max(Op1, Op2);
}


int main() {

	cin >> n >> k;
	taste.resize(n);
	calorie.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> taste[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> calorie[i];
	}

	memset(dp, -1, sizeof(dp));

	int ans = F(0, 0);//Starting Point

	if (ans <= 0) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}


}