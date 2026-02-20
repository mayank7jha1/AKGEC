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


	//We are brute forcing m:
	for (int m = 0; m <= 60; m++) {

		/*
			For a Particular Value of m we need to
			find a value of x.
		*/

		int B = pow(2, m) - 1;//2^m-1
		int s1 = 1, e = 1e10;

		/*
			What if x = 1 hain.
			n will be equal to B.
			and we know one pair.

			Pair(1,m) : This satisfies our equation.

			k=x*2^m : k=1*(B+1)

			k = 1*B+1;
			One Solution that is B+1.
		*/

		if (n == B) {
			s.insert(B + 1);
			continue;
		}

		//We are trying to find the value of x using BS.

		while (s1 <= e) {

			int T = 0;//Total Equation.
			int mid = (s1 + e) / 2;
			//Kya ye mid mera potential x bann sakta hain.

			T = mid;

			//Overflow.
			if (T > MX / (mid - 1)) {
				T = MX;
			} else {
				T *= (mid - 1);
				T /= 2;
			}



			/*
				Currently We have :
				B = 2^m-1;
				T=mid*(mid-1)/2;

				Mid is the potential value of x.

				Why currently I am not
				multiplying
				mid*B because there can be overflows.
			*/

			int p = B;

			if (p != 0 and mid > (MX / p)) {
				//Overflow will be there.
				//My T will be greater than MX when I apply
				//the full equation.
				T = MX;

			} else {
				//If overflow is not there.
				T += (mid * p);//Complete Equation is now made.
			}


			//When You are here you know have the
			//complete equation.

			if (T == n) {
				//We have found a pair.
				//x,m ka that satisfies the equation but
				//you have to be careful here as x has to be odd.
				if (mid % 2 == 1) {
					//Now this is a valid pair.
					s.insert(mid * (B + 1));
				}
			}


			if (T > n) {
				e = mid - 1;
			} else {
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