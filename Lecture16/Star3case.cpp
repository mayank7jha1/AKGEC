#include<iostream>
#include<climits>
using namespace std;


int Min_Step = INT_MAX;//THis will store the minimum steps to reach top across all paths.


void F(int *a, int n, int i, int count, bool *visited) {

	if (i == n) {
		Min_Step = min(count, Min_Step);
		return;
	}

	//Currently You are at the ith stair.
	visited[i] = 1;

	//Option 1: One step jump:
	if (i + 1 <= n and visited[i + 1] == 0) {
		F(a, n, i + 1, count + 1, visited);
	}

	//Option 2: Value kadam ka jump liya hain.
	if (i + a[i] <= n and i + a[i] >= 0 and visited[i + a[i]] == 0) {
		F(a, n, i + a[i], count + 1, visited);
	}

	//From this current box i you now cannot move any further henc you return to the
	//previous by reinstating the original state for this box i as 1 so that you can
	//visit this box i from a different path.

	visited[i] = 0;//backtracking
	return;
}




int main() {
	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;
		bool visited[n + 1] {0};
		int values[n] {0};

		for (int i = 0; i < n; i++) {
			cin >> values[i];
		}

		Min_Step = INT_MAX;
		F(values, n, 0, 0, visited);

		if (Min_Step == INT_MAX) {
			cout << -1 << endl;
		} else {
			cout << Min_Step << endl;
		}

	}

}