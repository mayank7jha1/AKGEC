#include<iostream>
using namespace std;
#define int long long
int n, d;
const int N = 2e5 + 1;
int a[N] {};



int32_t main() {

	cin >> n >> d;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int AB = 0;

	//Check if my answer exists or not.

	for (int i = 0; i < n; i++) {

		if (a[i] == 0) {
			//This is the day jab aapka AB check hoga and vo non negative hona chahiye also
			//you need to avoid overflow hence making your AB as minimum as possible.

			if (AB < 0) {
				AB = 0;
			}

		} else {
			AB += a[i];
			if (AB > d) {
				cout << "-1" << endl;
				return 0;
			}
		}
	}


	//If I am Standing here that would mean there is a answer that exists.

	//You need to minimise the visits also so you are putting the maximum amount
	//on a particular possible/

	AB = 0;
	int v = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			AB = d;
			v++;
		} else {
			AB += a[i];

			if (AB > d) {
				AB = d;
			}
		}
	}

	cout << v << endl;
}