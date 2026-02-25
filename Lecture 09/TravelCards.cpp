#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long

int n, f, a, b, k;




int32_t main() {

	cin >> n >> a >> b >> k >> f;

	map<pair<string, string>, int > mp;

	string prev = "";//This is for transhipment.

	for (int i = 0; i < n; i++) {

		string SP, EP;
		cin >> SP >> EP;

		int price = 0;
		if (prev == SP) {
			//This is a Transhipment
			price = b;
		} else {
			price = a;
		}

		prev = EP;

		if (SP > EP) {
			swap(SP, EP);
		}


		mp[ {SP, EP}] += price;
	}

	//Mujhe ye check karna hain ki konse konse route me travel card
	//kharidna hain.


	vector<int>cost; //This stores the cost of all the routes as elements.
	int TotalCost = 0;

	for (auto x : mp) {
		cost.push_back(x.second);
		TotalCost += x.second;
	}

	sort(cost.rbegin(), cost.rend());//Dec. Sort Mere pass dec. order me route ke cost aajayenge.

	for (int i = 0; i < cost.size() and i < k; i++) {

		if (cost[i] > f) {
			TotalCost = TotalCost - cost[i] + f;
		} else {
			// cost[i]<f and if this the scenario :
			//main aur travel card nahi kharid paaunga as
			//mere cost vector of routes is in dec. order.

			break;
		}


	}


	cout << TotalCost << endl;
}