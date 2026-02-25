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

		/*
			x : All the x co-ordinate
			y : All the y co-ordinate

			sx : All the x axis length/Segment.
			sy : all the y-axis length/segment.

		*/

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

				/*
					Main Work : If b was not already present in x as a co-ordinate.
					Now you need to create x axis me ek segment.
					I need to find out the co-ordinate in x that is just smaller than b.
					and also need to find out co-ordinate in x just greater than b.
				*/

				auto small = x.lower_bound(b); //This will return an iterator(Address) of a first block containing value >= b.
				small--;

				//Now my small is pointing to a value just smaller than b.
				//Small is an iterator containing an address of a block just
				//smaller than b.

				auto large = x.upper_bound(b); // > b.



				//Now small and large are two iterators containing the address
				//of two blocks containing values just smaller and greater than
				//b.

				//Now I need to insert two new segment in sx and remove one
				//segment in sx.

				sx.erase(sx.find(*large - *small));

				sx.insert(*large - b);
				sx.insert(b - *small);


				//Now update the co-ordinate in x also.
				x.insert(b);

				int LargestXSegment = *(--sx.end());
				int LargestYSegment = *(--sy.end());

				cout << LargestXSegment*LargestYSegment << endl;




			} else {	//a==1

				if (y.find(b) != y.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
					continue;
				}

				//Main Work : If b was not already present in y as a co-ordinate.





			}



		}





	}



}