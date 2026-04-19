#include<iostream>
using  namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
#define int long long
int Fact[N] {0};

//Addition Property
//O(1)
int Addition(int x, int y) {
	return (((x % mod) + (y % mod)) % mod);
}

//Subtraction Property
//O(1)
int Subtraction(int x, int y) {
	return (((x % mod) - (y % mod) + mod) % mod);
}

//Multiplication Property
//O(1)
int Multiplication(int x, int y) {
	return (((x % mod) * (y % mod)) % mod);
}

//Fast Power Using Recursion
//O(log2(n))
int Fast_Power2(int x, int y) {
	if (y == 0) {
		return 1;
	}
	int small_ans = Fast_Power2(x, y / 2);

	if (y % 2 == 1) {
		return small_ans * small_ans * x;
	} else {
		return small_ans * small_ans;
	}
}

//(Fast Power % P) Using Iteration
//(x^y)%mod
//O(log2(n)) : Bitmasking

int Fast_Power(int x, int y) {
	int result = 1;
	while (y > 0) {

		if (y % 2 == 1) {
			result = Multiplication(result, x);
		}

		//Remove the last bit
		y /= 2;
		x = Multiplication(x, x);
	}

	return result;
}

//(y^-1)%mod
//If mmod is a Prime Number:
//Fermat's Little Theoram:
int Inverse(int y) {
	return Fast_Power(y, mod - 2);
}

//O(log2(y))
//(x/y)%mod
int division(int x, int y) {
	return Multiplication(x, Inverse(y));
}

//Calculate Large Factorials
void Calculate_Factorial() {
	Fact[0] = 1;
	for (int i = 1; i <= N; i++) {
		Fact[i] = Multiplication(Fact[i - 1], i);
	}
}

/*
	nCr=(n!/r!*(n-r)!)

	t= n! * (r^-1)!
	t=t*((n-r)^-1)!

	int t=Multiplication(Fact[n],Inverse(Fact[r]));
	t=Multiplication(t,Inverse(Fact[n-r]));
*/

int nCr(int n, int r) {
	return Multiplication(Multiplication(Fact[n], Inverse(Fact[r])),
	                      Inverse(Fact[n - r]));
}


int32_t main() {
	int x = 5, y = 2;
	Calculate_Factorial();
	cout << nCr(x, y) << endl;
}