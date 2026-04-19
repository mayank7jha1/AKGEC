#include<iostream>
using  namespace std;

//Checks if the number is odd/Even
void OddEven(int x) {
	if ((x & 1) == 1) {
		cout << "Odd" << endl;
	} else {
		cout << "Even" << endl;
	}
}

//Fetch me the ith bit from right
int getithBit(int n, int i) {
	int mask = (1 << i);
	return ((n & mask) > 0 ? 1 : 0);
}

//Clear the ith bit from right
int ClearithBit(int &n, int i) {
	int mask = ~(1 << i);
	return (n & mask);
}

//Set the ith bit
void SetithBit(int &n, int i) {
	int mask = (1 << i);
	n = (n | mask);
	return;
}

//Update the ith bit
void UpdateithBit(int &n, int i, int v) {
	ClearithBit(n, i);
	int mask = (v << i);
	n = (n | mask);
	return;
}

void ClearLastibits(int &n, int i) {
	int mask = (-1 << i);
	n = n & mask;
	return;
}

void ClearInRange(int &n, int i, int j) {

	int a = (-1) << (j + 1);
	int b = (i << i) - 1;
	int mask = (a | b);

	n = (n & mask);
	return;
}

bool PowerOf2(int n) {
	if ((n & (n - 1)) == 0) {
		return true;
	}
	return false;
}



//Count Set Bit
int CountSetBit(int n) {
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}


int main() {
	cout << (~0) << endl;
	int x;
	cin >> x;
	OddEven(x);
	cout << getithBit(11, 0) << endl;
}

