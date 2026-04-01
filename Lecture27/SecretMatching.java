import java.io.*;
public class Main {
    static int[] par = new int[26];
    static int[] rnk = new int[26];
    static {
        // Initialize DSU: each node is its own parent (-1 means root)
        for (int i = 0; i < 26; i++) {
            par[i] = -1;
            rnk[i] = 1;
        }
    }
    static int find(int x) {
        if (par[x] == -1) return x;
        return par[x] = find(par[x]); // Path compression
    }
    static void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        // Union by rank
        if (rnk[px] < rnk[py]) {
            int tmp = px; px = py; py = tmp;
        }
        par[py] = px;
        rnk[px] += rnk[py];
    }

    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        boolean[] used = new boolean[26]; // Track which letters actually appear
        for (int i = 0; i < n; i++) {
            String s = br.readLine().trim();
            used[s.charAt(0) - 'a'] = true;
            for (int j = 1; j < s.length(); j++) {
                used[s.charAt(j) - 'a'] = true;
                unite(s.charAt(j - 1) - 'a', s.charAt(j) - 'a');
            }
        }

        // Count distinct components among used letters (at most 26 iterations)
        boolean[] seen = new boolean[26];
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (used[i]) {
                int root = find(i);
                if (!seen[root]) {
                    seen[root] = true;
                    ans++;
                }
            }
        }
        System.out.println(ans);
    }
}
