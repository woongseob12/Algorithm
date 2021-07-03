import java.io.*;
import java.util.*;

public class BOJ2056 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		@SuppressWarnings("unchecked")
		LinkedList<Integer>[] list = new LinkedList[n + 1];
		
		int[] arr = new int[n + 1];
		int[] in = new int[n + 1];
		for(int i = 1; i <= n; i++) {
			list[i] = new LinkedList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr[i] = Integer.parseInt(st.nextToken());
			int loop = Integer.parseInt(st.nextToken());
			while(loop-- > 0) {
				int pre = Integer.parseInt(st.nextToken());
				list[pre].add(i);
				in[i]++;
			}
		}
		
		PriorityQueue<Task> pq = new PriorityQueue<>();

		for(int i = 1; i <= n; i++) {
			if(in[i] == 0) {
				pq.add(new Task(arr[i], i));
			}
		}
		
		int ans = 0;

		while(!pq.isEmpty()) {
			Task curr = pq.poll();
			ans = curr.time;
			for(int i = 0; i < list[curr.seq].size(); i++) {
				int next = list[curr.seq].get(i);
				in[next]--;
				if(in[next] == 0) {
					pq.add(new Task(curr.time + arr[next], next));
				}
			}
		}
		
		System.out.println(ans);
	}
	
	static class Task implements Comparable<Task>{
		int time;
		int seq;

		public Task(int time, int seq) {
			super();
			this.time = time;
			this.seq = seq;
		}
		@Override
		public int compareTo(Task o) {
			return this.time - o.time;
		}
		
	}
}
