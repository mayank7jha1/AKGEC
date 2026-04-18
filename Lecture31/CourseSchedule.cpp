#include <vector>

using namespace std;

class Solution {
private:
	// Helper function for DFS cycle detection
	// visited states: 0 = Unvisited, 1 = Visiting (in stack), 2 = Fully Visited
	bool dfs_helper(int node, vector<vector<int>>& adj, vector<int>& visited) {
		visited[node] = 1; // Mark as 'Visiting'

		for (int nbr : adj[node]) {
			// Cycle detected!
			if (visited[nbr] == 1) {
				return false;
			}
			// If unvisited, recursively check
			if (visited[nbr] == 0) {
				if (!dfs_helper(nbr, adj, visited)) {
					return false;
				}
			}
		}

		visited[node] = 2; // Mark as 'Fully Visited'
		return true;       // No cycle from this path
	}

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		// 1. Build the Adjacency List
		vector<vector<int>> adj(numCourses);
		for (const auto& pre : prerequisites) {
			int course = pre[0];
			int prereq = pre[1];
			// To take 'course', you must first take 'prereq'.
			// Directed edge: prereq -> course
			adj[prereq].push_back(course);
		}

		// 2. Initialize the visited array
		vector<int> visited(numCourses, 0);

		// 3. Run DFS from every unvisited node
		// We use 0 to numCourses - 1 because the nodes are 0-indexed
		for (int i = 0; i < numCourses; i++) {
			if (visited[i] == 0) {
				// If dfs_helper returns false, a cycle was found.
				if (!dfs_helper(i, adj, visited)) {
					return false;
				}
			}
		}

		// If we processed all nodes without finding a cycle, we can finish.
		return true;
	}
};