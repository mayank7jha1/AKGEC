import java.io.InputStream;
import java.io.IOException;

public class SubordinatesRecursiveOpt {
    
    // Forward Star graph representation (Zero object creation, 100% flat memory)
    static int[] head;
    static int[] to;
    static int[] next;
    static int edgeCount = 0;
    
    static int[] dp;

    public static void main(String[] args) throws IOException {
        InputStream in = System.in;
        int n = readInt(in);

        // 1-based indexing
        head = new int[n + 1];
        to = new int[n + 1];   // A tree with N nodes has exactly N-1 edges
        next = new int[n + 1];
        dp = new int[n + 1];

        // Read edges and build the directed graph (Boss -> Subordinate)
        for (int i = 2; i <= n; i++) {
            int boss = readInt(in);
            addEdge(boss, i);
        }

        // Your exact top-down recursive call
        solve(1);

        // Fast output
        StringBuilder sb = new StringBuilder(n * 8);
        for (int i = 1; i <= n; i++) {
            sb.append(dp[i]).append(' ');
        }
        System.out.println(sb.toString());
    }
    
    // Function to add a directed edge using the Forward Star method
    static void addEdge(int u, int v) {
        edgeCount++;
        to[edgeCount] = v;              // Store the destination node
        next[edgeCount] = head[u];      // Point to the previous edge from node u
        head[u] = edgeCount;            // Update the head to this new edge
    }

    // Your exact recursive logic
    static void solve(int node) {
        int subordinate = 0;
        
        // Traverse all children using the flat arrays
        for (int e = head[node]; e != 0; e = next[e]) {
            int child = to[e];
            
            solve(child);
            // If you are standing here: Recursion calculated current child's subordinates.
            subordinate += 1 + dp[child];
        }
        
        dp[node] = subordinate;
    }

    // Custom byte-level reader for maximum I/O speed
    static int readInt(InputStream in) throws IOException {
        int c = in.read();
        while (c <= 32) {
            if (c == -1) return -1;
            c = in.read();
        }
        int res = 0;
        while (c > 32) {
            res = res * 10 + c - '0';
            c = in.read();
        }
        return res;
    }
}
