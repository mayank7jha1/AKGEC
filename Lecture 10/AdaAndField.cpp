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
					/*
						b is already present in x as a co - ordinate.
						set is a container : We cannot fetch any address directly.

						Idea: Since we are not creating any new division
						current largestxsegment and current largestysegment will remain same.

						Fetch them. They are stored in the multiset sx and sy.
						and since set stores values in asc. fecth the last values.

						vector : Ka address you cannot fetch directly .

						Isliye in c++ to fetch the address of a block we use iterators.
						Appke pass bahut tarah ke iterators hote hain that returns the
						address of the current block in container.

						.begin() : This iterator returns the address of the first block.
						.end() : This iterator returns the address of the (last block + 1 ).

						So in order to get the last values in set sx we say :

						sx.end() : Address of the last block + 1
						--sx.end() : This returns the address of the last block

						*(Address) : * is a value at operator it is used to fetch a value at
						a adress.

						*(--sx.end()) : This is going to return the last value present
						in set and since it is a set this value will be the largest.

					*/

					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());


					cout << LargestXSegment*LargestYSegment << endl;
				}



			} else {	//a==1

				if (y.find(b) != y.end()) {
					int LargestXSegment = *(--sx.end());
					int LargestYSegment = *(--sy.end());
					cout << LargestXSegment*LargestYSegment << endl;
				}



			}



		}





	}



}