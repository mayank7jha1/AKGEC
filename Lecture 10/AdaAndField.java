import java.io.*;
import java.util.*;

public class Main {

	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String line = br.readLine();
					if (line == null) return null;
					st = new StringTokenizer(line);
				} catch (IOException e) {
					e.printStackTrace();
					return null;
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			String str = next();
			if (str == null) return -1;
			return Integer.parseInt(str);
		}
	}

	public static void main(String[] args) {
		FastReader cin = new FastReader();
		StringBuilder out = new StringBuilder();

		String tStr = cin.next();
		if (tStr == null) return;
		int t = Integer.parseInt(tStr);

		while (t-- > 0) {
			int n = cin.nextInt();
			if (n == -1) break;
			int m = cin.nextInt();
			int q = cin.nextInt();

			TreeSet<Integer> x = new TreeSet<>();
			TreeSet<Integer> y = new TreeSet<>();
			TreeMap<Integer, Integer> sx = new TreeMap<>();
			TreeMap<Integer, Integer> sy = new TreeMap<>();

			x.add(0);
			x.add(n);

			y.add(0);
			y.add(m);

			sx.put(n, 1);
			sy.put(m, 1);

			for (int i = 0; i < q; i++) {

				int a = cin.nextInt();
				if (a == -1) break;
				int b = cin.nextInt();

				if (a == 0) {

					if (x.contains(b)) {
						long LargestXSegment = sx.lastKey();
						long LargestYSegment = sy.lastKey();
						out.append(LargestXSegment * LargestYSegment).append("\n");
						continue;
					}

					Integer smallObj = x.lower(b);
					Integer largeObj = x.higher(b);

					if (smallObj == null || largeObj == null) {
						long LargestXSegment = sx.lastKey();
						long LargestYSegment = sy.lastKey();
						out.append(LargestXSegment * LargestYSegment).append("\n");
						continue;
					}

					int small = smallObj;
					int large = largeObj;

					int diff = large - small;
					if (sx.get(diff) == 1) {
						sx.remove(diff);
					} else {
						sx.put(diff, sx.get(diff) - 1);
					}

					sx.put(large - b, sx.getOrDefault(large - b, 0) + 1);
					sx.put(b - small, sx.getOrDefault(b - small, 0) + 1);

					x.add(b);

					long LargestXSegment = sx.lastKey();
					long LargestYSegment = sy.lastKey();

					out.append(LargestXSegment * LargestYSegment).append("\n");

				} else {

					if (y.contains(b)) {
						long LargestXSegment = sx.lastKey();
						long LargestYSegment = sy.lastKey();
						out.append(LargestXSegment * LargestYSegment).append("\n");
						continue;
					}

					Integer smallObj = y.lower(b);
					Integer largeObj = y.higher(b);

					if (smallObj == null || largeObj == null) {
						long LargestXSegment = sx.lastKey();
						long LargestYSegment = sy.lastKey();
						out.append(LargestXSegment * LargestYSegment).append("\n");
						continue;
					}

					int small = smallObj;
					int large = largeObj;

					int diff = large - small;
					if (sy.get(diff) == 1) {
						sy.remove(diff);
					} else {
						sy.put(diff, sy.get(diff) - 1);
					}

					sy.put(large - b, sy.getOrDefault(large - b, 0) + 1);
					sy.put(b - small, sy.getOrDefault(b - small, 0) + 1);

					y.add(b);

					long LargestXSegment = sx.lastKey();
					long LargestYSegment = sy.lastKey();

					out.append(LargestXSegment * LargestYSegment).append("\n");
				}

			}
		}
		System.out.print(out);
	}
}
