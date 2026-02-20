#include<iostream>
#include<map>
#include<set>
#include<climits>
#include<math.h>
using namespace std;
#define int long long
#define MX LLONG_MAX


int32_t main() {
	int n;
	cin >> n;
	set<int>s;

	for (int m = 0; m <= 60; m++) {
		int B = pow(2, m) - 1;
		int s1 = 1, e = 2e9;//Exact Range.

		if (n == B) {
			s.insert(B + 1);
			continue;
		}

		while (s1 <= e) {

			int T = 0;//Total Equation.
			int mid = (s1 + e) / 2;

			T = mid;

			T *= (mid - 1);
			T /= 2;

			int p = B;

			if ((p != 0) and (mid > (MX / p))) {
				T = MX;

			} else {
				T += (mid * p);
			}

			if (T == n) {
				if ((mid % 2) == 1) {
					s.insert(mid * (B + 1));
				}
				break;
			}

			if (T > n) {
				e = mid - 1;
			}

			if (T < n) {
				s1 = mid + 1;
			}

		}
	}


	if (s.size() == 0) {
		cout << -1 << endl;
	} else {
		for (auto x : s) {
			cout << x << endl;
		}
	}
}