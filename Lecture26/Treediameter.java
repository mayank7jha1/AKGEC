import java.io.*;
import java.util.*;


public class Treediameter {
    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int) st.nval;
        // Array-based adjacency list (linked list style)
        int[] head = new int[n + 1];
        Arrays.fill(head, -1);
        int totalEdges = 2 * (n - 1);
        int[] to = new int[totalEdges];
        int[] next = new int[totalEdges];
        int edgeCount = 0;
        for (int i = 0; i < n - 1; i++) {
            st.nextToken(); int a = (int) st.nval;
            st.nextToken(); int b = (int) st.nval;
            to[edgeCount] = b;
            next[edgeCount] = head[a];
            head[a] = edgeCount++;
            to[edgeCount] = a;
            next[edgeCount] = head[b];
            head[b] = edgeCount++;
        }
        // Iterative DFS to get traversal order (root = 1)
        int[] order = new int[n];
        int[] par = new int[n + 1];
        int[] stack = new int[n];
        int top = 0, idx = 0;
        par[1] = 0;
        stack[top++] = 1;
        while (top > 0) {
            int node = stack[--top];
            order[idx++] = node;
            for (int e = head[node]; e != -1; e = next[e]) {
                int child = to[e];
                if (child != par[node]) {
                    par[child] = node;
                    stack[top++] = child;
                }
            }
        }
        // Process in reverse DFS order (leaves first, root last)
        // This combines both Solve() and Calculate() into one pass
        int[] downpath = new int[n + 1]; // longest path going down from node
        int[] diameter = new int[n + 1]; // diameter of subtree rooted at node
        for (int i = idx - 1; i >= 0; i--) {
            int node = order[i];
            int max1 = -1, max2 = -1; // top 2 child downpaths
            int maxDia = 0;           // best diameter from children (option 2)
            for (int e = head[node]; e != -1; e = next[e]) {
                int child = to[e];
                if (child != par[node]) {
                    // Track top 2 downpaths for option 1
                    int cp = downpath[child];
                    if (cp > max1) {
                        max2 = max1;
                        max1 = cp;
                    } else if (cp > max2) {
                        max2 = cp;
                    }
                    // Option 2: diameter lies entirely in a child's subtree
                    maxDia = Math.max(maxDia, diameter[child]);
                }
            }
            if (max1 == -1) {
                // Leaf node
                downpath[node] = 0;
                diameter[node] = 0;
            } else {
                // downpath = 1 + best child downpath
                downpath[node] = 1 + max1;
                // Option 1: path passes through this node
                int option1;
                if (max2 == -1) {
                    // Only one child
                    option1 = 1 + max1;
                } else {
                    // Two best children
                    option1 = 2 + max1 + max2;
                }
                // Final diameter = max(option1, option2)
                diameter[node] = Math.max(maxDia, option1);
            }
        }
        System.out.println(diameter[1]);
    }
}