#include<iostream>
#include<list>
#include<map>

using namespace std;

template<typename T>
class Graph {
	map<T, list<T>> mp;

public:
	void AddEdge(T x, T y) {
		mp[x].push_back(y);
		// Ensure 'y' is also added to the map even if it has no outgoing edges
		if (mp.find(y) == mp.end()) {
			mp[y] = list<T>();
		}
	}

	bool dfs_helper(T node, map<T, int>& visited, map<T, int>& Instack) {
		visited[node] = 1;
		Instack[node] = 1; // Add to current path (recursion stack)

		for (auto nbr : mp[node]) {
			// Case 1: Neighbor is unvisited. Recurse.
			if (visited[nbr] == 0) {
				if (dfs_helper(nbr, visited, Instack)) {
					return true; // Cycle found deeper down
				}
			}
			// Case 2: Neighbor is visited AND currently in the recursion stack.
			// This means we found a back-edge!
			else if (Instack[nbr] == 1) {
				return true;
			}
		}

		// Backtracking: Remove node from the current path before returning
		Instack[node] = 0;
		return false;
	}

	bool contains_cycle() {
		map<T, int> visited, Instack;

		// Initialize all known nodes to 0
		for (auto x : mp) {
			visited[x.first] = 0;
			Instack[x.first] = 0;
		}

		// Launch DFS from EVERY unvisited node to catch disconnected components
		for (auto x : mp) {
			T node = x.first;
			if (visited[node] == 0) {
				if (dfs_helper(node, visited, Instack)) {
					return true; // Cycle detected
				}
			}
		}

		return false; // No cycles found anywhere
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	Graph<int> gr;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		gr.AddEdge(x, y);
	}

	if (gr.contains_cycle()) {
		cout << "Cycle Detected!" << endl;
	} else {
		cout << "No Cycle Found." << endl;
	}

	return 0;
}