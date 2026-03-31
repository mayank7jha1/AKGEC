#include<bits/stdc++.h>
using namespace std;
vector<int>tree[200001];
int downpath[200001];
int diameter[200001];


void Solve(int node, int parent) {
	int leaf = 1;
	int ans = 0;
	for (auto child : tree[node]) {
		if (child != parent) {
			leaf = 0;
			Solve(child, node);
			ans = max(ans, downpath[child]);
		}
	}
	if (leaf == 1) {
		downpath[node] = 0;
	} else {
		downpath[node] = 1 + ans;
	}
	return;
}
void Calculate(int node, int parent) {
	int ans = 0;
	vector<int>childdownpaths;
	for (auto child : tree[node]) {
		if (child != parent) {
			Calculate(child, node);
			childdownpaths.push_back(downpath[child]);
			ans = max(ans, diameter[child]);
		}
	}
	int NoofChilds = childdownpaths.size();
	sort(childdownpaths.rbegin(), childdownpaths.rend());
	if (NoofChilds == 0) {
		diameter[node] = 0;
	} else if (NoofChilds == 1) {
		diameter[node] = 1 + childdownpaths[0];
	} else {
		diameter[node] = 2 + childdownpaths[0] + childdownpaths[1];
	}
	diameter[node] = max(ans, diameter[node]);
	return;
}
int main() {
	int n;
	cin >> n;


	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	Solve(1, 0);
	Calculate(1, 0);
	cout << diameter[1] << endl;
}
