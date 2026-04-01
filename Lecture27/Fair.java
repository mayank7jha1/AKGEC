import java.io.*;
import java.util.*;
public class Main {
    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken(); int n = (int) st.nval;
        st.nextToken(); int m = (int) st.nval;
        st.nextToken(); int k = (int) st.nval;
        st.nextToken(); int s = (int) st.nval;
        int[] a = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            st.nextToken();
            a[i] = (int) st.nval;
        }
        // Array-based adjacency list
        int[] head = new int[n + 1];
        Arrays.fill(head, -1);
        int totalEdges = 2 * m;
        int[] to = new int[totalEdges];
        int[] next = new int[totalEdges];
        int edgeCount = 0;
        for (int i = 0; i < m; i++) {
            st.nextToken(); int u = (int) st.nval;
            st.nextToken(); int v = (int) st.nval;
            to[edgeCount] = v;
            next[edgeCount] = head[u];
            head[u] = edgeCount++;
            to[edgeCount] = u;
            next[edgeCount] = head[v];
            head[v] = edgeCount++;
        }
        // sd[i][product] = shortest distance from town i to nearest town producing product
        int[][] sd = new int[n + 1][k + 1];
        for (int[] row : sd) Arrays.fill(row, -1);
        // Multi-source BFS for each product type
        int[] queue = new int[n + 1]; // array-based queue for speed
        for (int product = 1; product <= k; product++) {
            int qHead = 0, qTail = 0;
            // Enqueue all towns producing this product
            for (int i = 1; i <= n; i++) {
                if (a[i] == product) {
                    sd[i][product] = 0;
                    queue[qTail++] = i;
                }
            }
            // BFS
            while (qHead < qTail) {
                int node = queue[qHead++];
                for (int e = head[node]; e != -1; e = next[e]) {
                    int child = to[e];
                    if (sd[child][product] == -1) {
                        sd[child][product] = sd[node][product] + 1;
                        queue[qTail++] = child;
                    }
                }
            }
        }
        // For each town, sort distances and sum the s smallest
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            // Sort only the product distances (indices 1..k)
            // Copy to a temp array for sorting
            int[] dists = new int[k];
            for (int j = 0; j < k; j++) {
                dists[j] = sd[i][j + 1];
            }
            Arrays.sort(dists);
            int ans = 0;
            for (int j = 0; j < s; j++) {
                ans += dists[j];
            }
            sb.append(ans);
            if (i < n) sb.append(' ');
        }
        System.out.println(sb);
    }
}
