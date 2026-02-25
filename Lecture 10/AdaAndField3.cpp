#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int t;
	cin >> t;
	while (t--) {
		int n, m, q;
		cin >> n >> m >> q;

		multiset<int>x, y, sx, sy;

		x.insert(0);
		x.insert(n);

		y.insert(0);
		y.insert(m);

		sx.insert(n);
		sy.insert(m);


		for (int i = 0; i < q; i++) {

			int a, b;
			cin >> a >> b;

			if (a == 0) {

				if (x.find(b) != x.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				multiset<int>::iterator small = x.lower_bound(b); //>=b
				small--;
				auto large = x.upper_bound(b);

				sx.erase(sx.find(*large - *small));

				sx.insert(*large - b);
				sx.insert(b - *small);

				x.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());

				cout << LargestXSegment*LargestYSegment << endl;


			} else {

				if (y.find(b) != y.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}


				auto small = y.lower_bound(b);
				small--;
				auto large = y.upper_bound(b);

				sy.erase(sy.find(*large - *small));

				sy.insert(*large - b);
				sy.insert(b - *small);

				y.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());

				cout << LargestXSegment*LargestYSegment << endl;
			}

		}
	}

}

