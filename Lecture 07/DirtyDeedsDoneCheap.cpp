#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long


vector<int>f, s;

bool C1(int &x, int &y) {
	//Sort base on second value in desc. order.
	//0 and 4 : x=0 and y=4

	if (s[x] > s[y]) {
		return true;
	} else {
		return false;
	}
	//return (s[x] > s[y]);
}



bool C2(int &x, int &y) {
	//Sort Based on the first value in asc. order.
	return (f[x] < f[y]);
}



int32_t main() {
	int n;
	cin >> n;

	vector<int>s1, s2;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		f.push_back(x);
		s.push_back(y);

		if (x < y) {
			s1.push_back(i);
		} else {
			s2.push_back(i);
		}
	}


	if (s1.size() > s2.size()) {

		sort(s1.begin(), s1.end(), C1);

		cout << s1.size() << endl;
		for (auto x : s1) {
			cout << (x + 1) << " ";
		}
	} else {
		sort(s2.begin(), s2.end(), C2);
		cout << s2.size() << endl;
		for (auto x : s2) {
			cout << (x + 1) << " ";
		}
	}

}


// 0    1 7
// 1    6 4
// 2    2 10
// 3    9 8
// 4    3 5


// S1 : 0 2 4
// S2 : 1 5

// (f[0],s[0])---->(f[4],s[4])

// f: 1, 6, 2, 9, 3
// s: 7 4 10 8 5