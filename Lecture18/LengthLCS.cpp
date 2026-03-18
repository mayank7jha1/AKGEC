#include<iostream>
#include<cstring>
using namespace std;

int dp[3001][3001];



string getLCS(string &s, string &t, int i, int j, int LCS) {

	string ans = "";

	while (LCS > 0) {
		if (s[i] == t[j]) {
			ans.push_back(s[i]);
			i++, j++;
			LCS--;
		} else if (dp[i + 1][j] > dp[i][j + 1]) {

			//Answer string kuch update karna hain ? No.
			i++;

		} else {

			j++;
		}
	}

	return ans;

}



int F(string &s, string &t, int i, int j) {

	if (i == s.length() or j == t.length()) {
		return 0;
	}

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	if (s[i] == t[j]) {
		return dp[i][j] = 1 + F(s, t, i + 1, j + 1);
	} else {

		//You are saying s[i] is not part of answer.
		int Op1 = F(s, t, i + 1, j);


		//You are saying t[j] is not part of answer.
		int Op2 = F(s, t, i, j + 1);

		return dp[i][j] = max(Op1, Op2);
	}

}



int main() {

	string s, t;
	cin >> s >> t;
	memset(dp, -1, sizeof(dp));
	cout << F(s, t, 0, 0) << endl;
	cout << getLCS(s, t, 0, 0, F(s, t, 0, 0)) << endl;
}