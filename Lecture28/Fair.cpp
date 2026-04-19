#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

int n, m, k, s;
int sd[100001][101]; //This Stores the min distance for every town to every product.

int a[100001];//This stores the type of product ith town has.

vector<int>gr[100001];


void Solve() {
	memset(sd, -1, sizeof(sd));
	queue<int>q;

	for (int product = 1; product <= k; product++) {
		for (int i = 1; i <= n; i++) {
			if (a[i] == product) {
				sd[i][product] = 0;
				q.push(i);
			}
		}

		//Single Source Shortest Path Algo Logic: (For Unweighted Graph)
		while (!q.empty()) {
			int node = q.front();
			q.pop();

			for (auto child : gr[node]) {
				if (sd[child][product] == -1) {
					sd[child][product] = sd[node][product] + 1;
					q.push(child);
				}
			}
		}
	}


	for (int i = 1; i <= n; i++) {
		sort(sd[i] + 1, sd[i] + k + 1);

		int ans = 0;
		for (int j = 1; j <= s; j++) {
			ans += sd[i][j];
		}

		cout << ans << " ";
	}

}





int main() {
	cin >> n >> m >> k >> s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr[x].push_back(y);
		gr[y].push_back(x);
	}


	Solve();

}