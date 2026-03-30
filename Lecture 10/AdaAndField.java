import java.io.*;
import java.util.*;

public class Main {
    static class MultiSet {
        PriorityQueue<Long> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        HashMap<Long, Integer> counts = new HashMap<>();

        void add(long val) {
            maxHeap.add(val);
            counts.put(val, counts.getOrDefault(val, 0) + 1);
        }

        void remove(long val) {
            counts.put(val, counts.get(val) - 1);
        }

        long getMax() {
            while (!maxHeap.isEmpty() && counts.get(maxHeap.peek()) == 0) {
                maxHeap.poll();
            }
            return maxHeap.isEmpty() ? 0 : maxHeap.peek();
        }
    }

    static class FastScanner {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public FastScanner(InputStream stream) {
            this.stream = stream;
        }

        private int read() {
            if (numChars == -1) return -1;
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    return -1;
                }
                if (numChars <= 0) return -1;
            }
            return buf[curChar++];
        }

        private boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t';
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            if (c == -1) return -1;
            int res = 0;
            do {
                res = res * 10 + c - '0';
                c = read();
            } while (c != -1 && !isSpaceChar(c));
            return res;
        }

        public long nextLong() {
            int c = read();
            while (isSpaceChar(c)) c = read();
            if (c == -1) return -1;
            long res = 0;
            do {
                res = res * 10 + c - '0';
                c = read();
            } while (c != -1 && !isSpaceChar(c));
            return res;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int t = sc.nextInt();
        if (t == -1) return;

        while (t-- > 0) {
            long n = sc.nextLong();
            long m = sc.nextLong();
            int q = sc.nextInt();

            TreeSet<Long> x = new TreeSet<>();
            TreeSet<Long> y = new TreeSet<>();
            
            MultiSet sx = new MultiSet();
            MultiSet sy = new MultiSet();

            x.add(0L);
            x.add(n);
            y.add(0L);
            y.add(m);

            sx.add(n);
            sy.add(m);

            for (int i = 0; i < q; i++) {
                int type = sc.nextInt();
                long b = sc.nextLong();

                if (type == 0) { // Vertical Cut
                    if (x.contains(b)) {
                        out.append(sx.getMax() * sy.getMax()).append("\n");
                        continue;
                    }

                    Long small = x.lower(b);
                    Long large = x.higher(b);

                    if (small != null && large != null) {
                        sx.remove(large - small);
                        sx.add(large - b);
                        sx.add(b - small);
                        x.add(b);
                    }
                    out.append(sx.getMax() * sy.getMax()).append("\n");

                } else { // Horizontal Cut
                    if (y.contains(b)) {
                        out.append(sx.getMax() * sy.getMax()).append("\n");
                        continue;
                    }

                    Long small = y.lower(b);
                    Long large = y.higher(b);

                    if (small != null && large != null) {
                        sy.remove(large - small);
                        sy.add(large - b);
                        sy.add(b - small);
                        y.add(b);
                    }
                    out.append(sx.getMax() * sy.getMax()).append("\n");
                }
            }
        }
        System.out.print(out);
    }
}
