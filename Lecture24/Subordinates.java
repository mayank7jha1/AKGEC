import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Subordinates {

    // Array of ArrayLists to act similarly to vector<int> tree[]
    static ArrayList<Integer>[] tree;

    public static void main(String[] args) throws IOException {
        // Fast I/O for reading inputs quickly
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());

        // Initialize the adjacency list
        tree = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) {
            tree[i] = new ArrayList<>();
        }

        // Read the tree edges
        if (n > 1) {
            st = new StringTokenizer(br.readLine());
            for (int i = 2; i <= n; i++) {
                int x = Integer.parseInt(st.nextToken());
                tree[x].add(i);
                tree[i].add(x);
            }
        }

        // dp array initialized to 0 by default in Java
        int[] dp = new int[n + 1];

        solve(1, 0, dp);

        // Fast I/O for printing output quickly
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= n; i++) {
            sb.append(dp[i]).append(" ");
        }

        System.out.println(sb.toString().trim());
    }

    static void solve(int node, int parent, int[] dp) {
        int subordinate = 0;

        for (int child : tree[node]) {
            if (child != parent) {
                solve(child, node, dp);
                // If You are standing here: Recursion calculated current child's subordinates.
                subordinate += 1 + dp[child];
            }
        }

        dp[node] = subordinate;
    }
}
