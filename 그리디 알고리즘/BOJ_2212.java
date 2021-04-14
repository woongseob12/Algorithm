import java.io.*;
import java.util.*;

public class BOJ_2212 {
	static int N, K;
	static Set<Integer> arr = new HashSet<>();
	static Info[] diff;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			arr.add(Integer.parseInt(st.nextToken()));
		}
		List<Integer> list = new ArrayList<>(arr);
		Collections.sort(list);
		int len = list.size();
		diff = new Info[len - 1];
		for (int i = 0; i < len - 1; i++) {
			diff[i] = new Info(list.get(i + 1) - list.get(i), i);
		}

		Arrays.sort(diff);
		int sum = 0;
		for(int i = 0 ; i <= diff.length - K; i++) {
			sum += diff[i].diff;
		}
		System.out.println(sum);
	}
	static class Info implements Comparable<Info>{
		int diff;
		int idx;
		public Info(int diff, int idx) {
			super();
			this.diff = diff;
			this.idx = idx;
		}
		@Override
		public int compareTo(Info o) {
			if(this.diff == o.diff) {
				return o.idx - this.idx;
			}
			return this.diff - o.diff;
		}
	}
}
