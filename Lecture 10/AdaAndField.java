import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder out = new StringBuilder();
        
        int t = sc.nextInt();

        while (t-- > 0) {
            long n = sc.nextLong();
            long m = sc.nextLong();
            int q = sc.nextInt();

            TreeSet<Long> x = new TreeSet<>();
            TreeSet<Long> y = new TreeSet<>();
            
            TreeMap<Long, Integer> sx = new TreeMap<>();
            TreeMap<Long, Integer> sy = new TreeMap<>();

            x.add(0L);
            x.add(n);

            y.add(0L);
            y.add(m);

            sx.put(n, 1);
            sy.put(m, 1);

            for (int i = 0; i < q; i++) {
                int type = sc.nextInt();
                long b = sc.nextLong();

                if (type == 0) {
                    
                    if (x.contains(b)) {
                        out.append(sx.lastKey() * sy.lastKey()).append("\n");
                        continue;
                    }

                    Long small = x.lower(b);
                    Long large = x.higher(b);

                    if (small == null || large == null) {
                        out.append(sx.lastKey() * sy.lastKey()).append("\n");
                        continue;
                    }

                    long diff = large - small;
                  
                    if (sx.get(diff) == 1) {
                        sx.remove(diff);
                    } else {
                        sx.put(diff, sx.get(diff) - 1);
                    }

                    sx.put(large - b, sx.getOrDefault(large - b, 0) + 1);
                    sx.put(b - small, sx.getOrDefault(b - small, 0) + 1);

                    x.add(b);

                    out.append(sx.lastKey() * sy.lastKey()).append("\n");

                } else { 
                    
                    if (y.contains(b)) {
                        out.append(sx.lastKey() * sy.lastKey()).append("\n");
                        continue;
                    }

                    Long small = y.lower(b);
                    Long large = y.higher(b);

                    if (small == null || large == null) {
                        out.append(sx.lastKey() * sy.lastKey()).append("\n");
                        continue;
                    }

                    long diff = large - small;
                    
                    if (sy.get(diff) == 1) {
                        sy.remove(diff);
                    } else {
                        sy.put(diff, sy.get(diff) - 1);
                    }

                    sy.put(large - b, sy.getOrDefault(large - b, 0) + 1);
                    sy.put(b - small, sy.getOrDefault(b - small, 0) + 1);

                    y.add(b);

                    out.append(sx.lastKey() * sy.lastKey()).append("\n");
                }
            }
        }
  
        System.out.print(out);
        sc.close();
    }
}
