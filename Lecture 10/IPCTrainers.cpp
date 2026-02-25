#include<iostream>
#include<queue>
#include<set>
using namespace std;
const int N = 1e5;


int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, d;
		cin >> n >> d;

		int AD[N] {}, Lecture[N] {}, Sadness[N] {};
		int LecturesTaken[N] {};

		//Priority Queue:

		priority_queue<pair<int, int>>mh;
		//{Sadness,Index}


		for (int i = 0; i < n; i++) {
			cin >> AD[i] >> Lecture[i] >> Sadness[i];
			mh.push({Sadness[i], i});
		}


		set<int>AvailableDays;
		for (int i = 1; i <= d; i++) {
			AvailableDays.insert(i);
		}


		while (!mh.empty()) {

			auto teacher = mh.top();
			mh.pop();

			int Arrival = AD[teacher.second];
			int Optimistic_End_Day = Arrival + Lecture[teacher.second] - 1;


			for (int i = Arrival; i <= Optimistic_End_Day; i++) {

				auto it = AvailableDays.lower_bound(i);

				if (it == AvailableDays.end()) {
					break;
				} else {
					AvailableDays.erase(it);
					LecturesTaken[teacher.second]++;
				}
			}
		}


		int ans = 0;

		for (int i = 0; i < n; i++) {
			ans += ((Lecture[i] - LecturesTaken[i]) * Sadness[i]);
		}

		cout << ans << endl;
	}


}