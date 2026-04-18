#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool dfs_helper(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& Instack, vector<int>& order) {
        visited[node] = 1;
        Instack[node] = 1; // Add to current recursion stack

        for (int nbr : adj[node]) {
            // Case 1: Unvisited neighbor
            if (visited[nbr] == 0) {
                if (dfs_helper(nbr, adj, visited, Instack, order)) {
                    return true; // Cycle detected deep down
                }
            }
            // Case 2: Visited and in stack (Back-edge / Cycle)
            else if (Instack[nbr] == 1) {
                return true;
            }
        }

        // Backtrack
        Instack[node] = 0;
        order.push_back(node);

        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 1. Build the Adjacency List
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            // Directed edge: prereq -> course
            adj[prereq].push_back(course);
        }

        // 2. Initialize trackers
        vector<int> visited(numCourses, 0);
        vector<int> Instack(numCourses, 0);
        vector<int> order;

        // 3. Run DFS from every unvisited node
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                // If a cycle is detected, it is impossible to finish the courses.
                // The problem states we must return an empty array in this case.
                if (dfs_helper(i, adj, visited, Instack, order)) {
                    return {};
                }
            }
        }

        // 4. Reverse the post-order sequence to get the correct Topological Sort
        reverse(order.begin(), order.end());

        return order;
    }
};