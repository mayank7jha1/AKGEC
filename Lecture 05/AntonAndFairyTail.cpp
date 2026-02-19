#include<iostream>
using namespace std;
#define int long long

//64-bit

int32_t main() {

	int n, m;
	cin >> n >> m;

	int ans = 0;//I initialise it with a value that can never become your answer.

	if (m >= n) {
		cout << n << endl;
		return 0;
	}


	int s = 0, e = 2e9;
	int target = n - m;

	/*
		The first value of k that satisfies the equation :
		k*(k+1)/2 >= (n-m).
	*/

	while (s <= e) {
		int mid = (s + e) / 2;
		int value = (mid * (mid + 1)) / 2;

		if (value >= target) {
			//This mid is your potential answer.
			ans = mid;
			e = mid - 1;
		} else {
			s = mid + 1;
		}

	}

	cout << ans + m << endl;
}



//Long long : 10^18 with precision chahiye upto 19 digits.

// 64 - bit system me : Ye sizes hain.
//double : 10^308 with precision upto 14/15 significant digits tak.(8 byte)
//Float : 10^38 with precision upto 7 significant digits.(4 byte)