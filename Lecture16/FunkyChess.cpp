#include<iostream>
using namespace std;
const int N = 10;
int n;
int grid[10][10], TO = 0, ans = -1;


/*
	ans : Across all the paths what is the maximum boxes value path ka count.
	count : Current path me kitne boxes ab tak visit karliye.
*/

int dx[] {1, 1, 2, 2, -1, -1, -2, -2};
int dy[] {2, -2, 1, -1, 2, -2, -1, 1};

/*

	(x,y) ---->x+dx[i],y+dy[i] for every i in range 0 to 7.

*/

void Input_Grid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				TO++;//THis is a valid chessboard vala box.
			}
		}
	}
}


void F(int x, int y, int count) {

	//Stoping Point : Updation.
	ans = max(ans, count);


	//Currently I am at x,y co-ordinate:

	for (int i = 0; i < 8; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];

		if (new_x >= 0 and new_x <= N and new_y >= 0 and new_y <= N and
		        grid[new_x][new_y] == 1) {
			//This new_x,new_y is a valid box.

			//Task :
			grid[new_x][new_y] = 0;//You don't want to revisit this box during the current path.
			F(new_x, new_y, count + 1);

			//Mera current path khatam now I can say ki kisi aur raste se
			//main new_x and new_y par aana chahunga hence

			grid[new_x][new_y] = 1;//Backtracking
		}
	}

	//Mera current box is still x,y.

	//Main x,y box se aage ab nahi badh sakta and I return to previous box.
	return;
}



int main() {
	cin >> n;
	Input_Grid();

	if (grid[0][0] == 0) {
		cout << "INvalid Input " << endl;
		cout << -1 << endl;
		return 0;
	}

	grid[0][0] = 0;//because every path will start from this point.
	//Hence Count=1 symbolising you have traversed one box in the current path.

	F(0, 0, 1);

	cout << TO - ans << endl;
}
