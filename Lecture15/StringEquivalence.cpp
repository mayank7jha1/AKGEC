#include<iostream>
using namespace std;
int n;
char output[15]; //string output;
int count = 0;


/*
	Time Complexity : No of States * Transition Time


*/

void F(int i, char mx) {

	//Stopping Point.
	if (i == n) {
		count++;
		output[i] = '\0';//In C++ character arrays always end with a NULL character.
		cout << output << endl;
		return;
	}

	//You can put any character from a to mx at the current index.
	for (char ch = 'a'; ch <= mx; ch++) {
		output[i] = ch;

		if (ch == mx) {
			F(i + 1, mx + 1);
		} else {
			F(i + 1, mx);
		}

	}

	return;
}


int main() {
	cin >> n;
	F(0, 'a');//Starting Point.
	cout << count << endl;
}



/*
	_ _ _ _ _ : 5!*(26)
	5!
*/