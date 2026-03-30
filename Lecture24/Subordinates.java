import java.io.InputStream;
import java.io.IOException;

public class Subordinates {
    
    // Using a 2D primitive array instead of ArrayList<Integer>[]
    static int[][] tree;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        InputStream in = System.in;
        
        int n = readInt(in);
        
        int[] boss = new int[n + 1];
        int[] degree = new int[n + 1];
        
        // Read bosses and count the out-degree (number of subordinates) for each node
        for (int i = 2; i <= n; i++) {
            boss[i] = readInt(in);
            degree[boss[i]]++;
        }
        
        // Initialize the jagged array based on exact degrees (zero wasted memory)
        tree = new int[n + 1][];
        for (int i = 1; i <= n; i++) {
            tree[i] = new int[degree[i]];
        }
        
        // Populate the tree (Directed edges: Boss -> Subordinate)
        int[] ptr = new int[n + 1];
        for (int i = 2; i <= n; i++) {
            int b = boss[i];
            tree[b][ptr[b]++] = i;
        }
        
        dp = new int[n + 1];
        
        // Start DFS from the general director
        solve(1);
        
        // Pre-allocate StringBuilder capacity to prevent resizing
        StringBuilder sb = new StringBuilder(n * 6);
        for (int i = 1; i <= n; i++) {
            sb.append(dp[i]).append(' ');
        }
        
        System.out.println(sb.toString());
    }
    
    static void solve(int node) {
        int subordinateCount = 0;
        
        // Iterate through primitive array (highly cache-friendly)
        for (int child : tree[node]) {
            solve(child);
            subordinateCount += 1 + dp[child];
        }
        
        dp[node] = subordinateCount;
    }
    
    // Custom byte-level reader for maximum I/O speed
    static int readInt(InputStream in) throws IOException {
        int c = in.read();
        while (c <= 32) { // Skip whitespaces
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
