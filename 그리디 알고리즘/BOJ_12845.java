import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_12845 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] card = new int[n];
		boolean[] used = new boolean[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		PriorityQueue<Info> pq = new PriorityQueue<>();
		for(int i = 0 ; i < n; i++) {
			card[i] = Integer.parseInt(st.nextToken());
			pq.add(new Info(card[i], i));
		}
		
		int sum = 0;
		while(!pq.isEmpty()) {
			Info temp = pq.poll();
			if(used[temp.idx]) {continue;}
			used[temp.idx] = true;
			if(temp.idx + 1 <= n - 1 && !used[temp.idx + 1]) {
				sum += temp.val + card[temp.idx + 1];
				pq.add(new Info(temp.val, temp.idx + 1));
			}
			if(temp.idx - 1 >= 0 && !used[temp.idx - 1]) {
				sum += temp.val + card[temp.idx - 1];
				pq.add(new Info(temp.val, temp.idx - 1));
			}
		}
		System.out.println(sum);
	}
	static class Info implements Comparable<Info>{
		int val;
		int idx;
		public Info(int val, int idx) {
			super();
			this.val = val;
			this.idx = idx;
		}
		@Override
		public int compareTo(Info o) {
			if(o.val == this.val) {
				return o.idx - this.idx;
			}
			return o.val - this.val;
		}
	}
}
