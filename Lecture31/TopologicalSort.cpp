#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V; // Total number of vertices
    vector<vector<int>> adj;

public:
    // Constructor to initialize the graph with N vertices
    Graph(int V) {
        this->V = V;
        adj.resize(V + 1); // +1 to support 1-based indexing
    }

    void AddEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Returns false if a cycle is detected, true otherwise
    bool dfs_helper(int node, vector<int>& visited, list<int>& order) {
        visited[node] = 1; // Mark as 'Visiting' (currently in the recursion stack)

        for (int nbr : adj[node]) {
            // If the neighbor is also currently being visited, we found a cycle!
            if (visited[nbr] == 1) {
                return false;
            }
            // If unvisited, recurse
            if (visited[nbr] == 0) {
                if (!dfs_helper(nbr, visited, order)) {
                    return false; // Propagate the cycle detection upwards
                }
            }
        }

        visited[node] = 2; // Mark as 'Fully Visited'
        order.push_front(node); // Push to front of the list before returning
        return true;
    }

    void topologicalSort() {
        // 0 = Unvisited, 1 = Visiting (in stack), 2 = Fully Visited
        vector<int> visited(V + 1, 0);
        list<int> order;

        // Check every node from 1 to V to ensure isolated nodes are included
        for (int i = 1; i <= V; i++) {
            if (visited[i] == 0) {
                if (!dfs_helper(i, visited, order)) {
                    cout << "Error: Graph contains a cycle. Topological sort is impossible." << endl;
                    return;
                }
            }
        }

        // Print the valid topological sort
        for (int node : order) {
            cout << node << " ";
        }
        cout << endl;
    }
};



int main() {
    int n, m;
    cin >> n >> m;

    Graph gr(n);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        gr.AddEdge(x, y);
    }

    gr.topologicalSort();

    return 0;
}