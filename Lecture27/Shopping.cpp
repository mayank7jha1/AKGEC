#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int col, row;
int dist[26][26];
char a[25][25];
int scr_x, scr_y;
int des_x, des_y;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool IsPossible(int x, int y) {
	return (x >= 0 && x < row && y >= 0 && y < col && a[x][y] != 'X');
}


void Dijkstra() {
	dist[scr_x][scr_y] = 0;
	// Min-heap: {distance, {x, y}}
	priority_queue<pair<int, pair<int, int>>,
	               vector<pair<int, pair<int, int>>>,
	               greater<pair<int, pair<int, int>>>> pq;
	pq.push({0, {scr_x, scr_y}});

	while (!pq.empty()) {
		auto d = pq.top().first;
		auto pos = pq.top().second;
		pq.pop();
		auto cx = pos.first;
		auto cy = pos.second;

		// Skip outdated entries
		if (d > dist[cx][cy]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (IsPossible(nx, ny)) {
				int newDist = dist[cx][cy] + (a[cx][cy] - '0');
				if (newDist < dist[nx][ny]) {
					dist[nx][ny] = newDist;
					pq.push({newDist, {nx, ny}});
				}
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> col >> row;
	while (col && row) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> a[i][j];
				dist[i][j] = 1e9;
				if (a[i][j] == 'S') {
					scr_x = i; scr_y = j;
					a[i][j] = '0';
				} else if (a[i][j] == 'D') {
					des_x = i; des_y = j;
					a[i][j] = '0';
				}
			}
		}
		Dijkstra();
		cout << dist[des_x][des_y] << '\n';
		cin >> col >> row;
	}
}
