import java.io.*;
import java.util.*;
public class TreeMatching {
    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int) st.nval;
        // Array-based adjacency list
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
        // dp[node][0] = max matching when node is NOT matched to a child
        // dp[node][1] = max matching when node IS matched to one child
        int[][] dp = new int[n + 1][2];
        // Process in reverse DFS order (leaves first, root last)
        for (int i = idx - 1; i >= 0; i--) {
            int node = order[i];
            // Exclude: each child contributes its best
            for (int e = head[node]; e != -1; e = next[e]) {
                int child = to[e];
                if (child != par[node]) {
                    dp[node][0] += Math.max(dp[child][0], dp[child][1]);
                }
            }
            // Include: try matching node with each child
            for (int e = head[node]; e != -1; e = next[e]) {
                int child = to[e];
                if (child != par[node]) {
                    // Match edge (node, child):
                    //   child contributes dp[child][0] (used upward, can't match down)
                    //   all OTHER children: already in dp[node][0], subtract this child's
                    //   contribution and add dp[child][0] instead
                    int candidate = 1 + dp[child][0]
                                    + dp[node][0] - Math.max(dp[child][0], dp[child][1]);
                    dp[node][1] = Math.max(dp[node][1], candidate);
                }
            }
        }
        System.out.println(Math.max(dp[1][0], dp[1][1]));
    }
}
