#include<iostream>
#include<climits>
using namespace std;
int target;

/*
	F(x,y) : Min Steps from x,y to Target.

	Time Complexity : No. of states * Transition Time.

	//~~2^n : 2^10^6
	1 sec : No.
*/


int F(int x, int y) {

	//Stoping Point : Smallest Subproblem ka answer.

	if (x > target or y > target) {
		//This is a invalid Path :
		//I should return a value that can never become an answer in this scenario.
		return 1e8;
	}

	/*
		F(target,y) or F(x,target) : Min steps to reach target from this is zero.
	*/

	if (x == target or y == target) {
		return 0;
	}


	//Task & Next State :
	int Op1 = F(x + y, y);
	int Op2 = F(x, x + y);


	//Current State is  F(x,y):
	return 1 + min(Op1, Op2);
}


int ans = INT_MAX;//Min steps across all the paths.
//count : Steps in the current path.

void F2(int x, int y, int count) {

	if (x == 1 and y == 1) {
		//Check if the current path is min step vala path.
		ans = min(ans, count);
		return;
	}

	if (x - y > 0) {
		F2(x - y, y, count + 1);
	}

	if (y - x > 0) {
		F2(x, y - x, count + 1);
	}

	return;
}


int main() {
	cin >> target;
	cout << F(1, 1) << endl;//Starting Point

	for (int i = 1; i <= target - 1; i++) {
		F2(i, target - i, 1);//Starting Point.
	}

	cout << ans << endl;

	// cout << "Mayakl";
}