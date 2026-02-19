#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
#define PI 3.14159265

double F(double x, double b, double c) {
	return (((x * x) + (b * x) + c) / sin(x));
}

double F1(double x, double b, double c) {
	return ((((2 * x) + b) * sin(x)) - (cos(x) * ((x * x) + (b * x) + c)));
}

//Method 1:
double IsThisJee(double b, double c) {
	double s = 0, e = PI / 2;

	int count = 0;
	double ans = -1;//Potential answer.

	while (s <= e) {
		double mid = (s + e) / 2;
		double slope = F1(mid, b, c);//Derivative

		if (slope > 0) {
			e = mid;
			ans = mid;
		} else {
			s = mid;
			ans = mid;
		}

		count++;
		if (count > 100) {
			break;
		}
	}

	return ans;
}

//Method 2: Using Ternary Search : Type 2 Implementation

double IsThisJee2(double b, double c) {
	double s = 0;
	double e = PI / 2;

	double error = 1e-6;
	double ans = -1;//Potential answer.

	while ((e - s) > error) {
		double m1 = s + (e - s) / 3;
		double m2 = e - (e - s) / 3;


		if (F(m1, b, c) > F(m2, b, c)) {
			s = m1;
			ans = m2;
		} else if (F(m1, b, c) < F(m2, b, c)) {
			e = m2;
			ans = m1;
		} else {
			ans = m1;
			s = m1, e = m2;
		}
	}

	return ans;
}


int main() {

	int t;
	cin >> t;

	while (t--) {
		double b, c;
		cin >> b >> c;

		double val = IsThisJee(b, c);
		double val2 = IsThisJee2(b, c);
		//cout << val2 << endl;
		cout << fixed << setprecision(10) << F(val, b, c) << endl;
		cout << fixed << setprecision(10) << F(val2, b, c) << endl;
	}


}