#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Comparators:
bool compare1(int &x, int &y) {

	//Asc. Order me sort karna hain.

	if (x < y) {
		return true;
	} else {
		return false;
	}

}



void BubbleSort(vector<int>&a, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (compare(a[j], a[j + 1]) == 1) {
				swap(a[j], a[j + 1]);
			}
		}
	}

	return;
}


//Comparators Returns only true or false.
//When comparators return true that means you tell your compiler that everything is fine and don't do anything.
//If your comparators returns false : swaping kardo jo do element aapne choose kare hain abhi unko.
bool compare(int &x, int &y) {

	// if (x > y) {
	// 	return false;
	// } else {
	// 	return true;
	// }

	// if (x < y) {
	// 	return true;
	// } else {
	// 	return false;
	// }


	return (x < y);

}


int main() {

	int n;
	cin >> n;

	vector<int>a{5, 1, 9, 19, 12};

	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }

	// BubbleSort(a, n);

	for (auto x : a) {
		cout << x << " ";
	}


	sort(a.begin(), a.end(), compare);



}



/*

	STL : sort(Address of the first block,address of the last block+1,Comparators);

	In c++: you cannot fetch an address of a container directly?

	int a[10];

	cout<<a<<endl; a is the base address of this array.
	vector is a container :

	iterators : Containers.

	Iterators and Pointers me difference kya hota hain?


	sort(,,Compator).


	Comparators : Tells you how any two elements of the container will be compared.


	//What are iterators.
	//Comparators  and Lamda functions.
	//How do you pass a function inside a function as a argument.



*/