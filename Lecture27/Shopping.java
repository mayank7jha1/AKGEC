import java.io.*;
import java.util.*;
public class Main {
    static final int[] dx = {0, 0, 1, -1};
    static final int[] dy = {1, -1, 0, 0};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            StringTokenizer st = new StringTokenizer(line);
            int col = Integer.parseInt(st.nextToken());
            int row = Integer.parseInt(st.nextToken());
            if (col == 0 && row == 0) break;
            char[][] a = new char[row][col];
            int[][] dist = new int[row][col];
            int srcX = 0, srcY = 0, desX = 0, desY = 0;
            for (int i = 0; i < row; i++) {
                String s = br.readLine().trim();
                for (int j = 0; j < col; j++) {
                    a[i][j] = s.charAt(j);
                    dist[i][j] = Integer.MAX_VALUE;
                    if (a[i][j] == 'S') {
                        srcX = i; srcY = j;
                        a[i][j] = '0'; // S has 0 cost
                    } else if (a[i][j] == 'D') {
                        desX = i; desY = j;
                        a[i][j] = '0'; // D has 0 cost
                    }
                }
            }
            // Dijkstra with min-heap: {distance, x, y}
            dist[srcX][srcY] = 0;
            PriorityQueue<int[]> pq = new PriorityQueue<>((p, q) -> p[0] - q[0]);
            pq.offer(new int[] {0, srcX, srcY});
            while (!pq.isEmpty()) {
                int[] curr = pq.poll();
                int d = curr[0], cx = curr[1], cy = curr[2];
                // Skip outdated entries
                if (d > dist[cx][cy]) continue;
                for (int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && a[nx][ny] != 'X') {
                        int newDist = dist[cx][cy] + (a[cx][cy] - '0');
                        if (newDist < dist[nx][ny]) {
                            dist[nx][ny] = newDist;
                            pq.offer(new int[] {newDist, nx, ny});
                        }
                    }
                }
            }
            sb.append(dist[desX][desY]).append('\n');
        }
        System.out.print(sb);
    }
}
