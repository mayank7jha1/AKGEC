import java.io.InputStream;
import java.io.IOException;

public class Subordinates {

    public static void main(String[] args) throws IOException {
        InputStream in = System.in;
        int n = readInt(in);
        
        int[] boss = new int[n + 1];
        int[] degree = new int[n + 1];
        
        // Read bosses and calculate the out-degree of each node
        for (int i = 2; i <= n; i++) {
            boss[i] = readInt(in);
            degree[boss[i]]++; // Count how many direct children the boss has
        }
        
        int[] dp = new int[n + 1];
        int[] q = new int[n + 1];
        int head = 0, tail = 0;
        
        // Enqueue all leaf nodes (employees with 0 subordinates)
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q[tail++] = i;
            }
        }
        
        // Process from bottom to top (Iterative Topological Sort)
        while (head < tail) {
            int current = q[head++];
            int currentBoss = boss[current];
            
            // If the current node has a boss, pass the subordinate count upwards
            if (currentBoss != 0) {
                dp[currentBoss] += dp[current] + 1;
                degree[currentBoss]--;
                
                // If the boss has received counts from all direct children, enqueue the boss
                if (degree[currentBoss] == 0) {
                    q[tail++] = currentBoss;
                }
            }
        }
        
        // Fast Output
        StringBuilder sb = new StringBuilder(n * 8);
        for (int i = 1; i <= n; i++) {
            sb.append(dp[i]).append(' ');
        }
        System.out.println(sb.toString());
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
