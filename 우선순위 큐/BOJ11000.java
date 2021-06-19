import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class BOJ11000 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		ArrayList<Time> list = new ArrayList<>();
		
		for(int i = 0 ; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());
			list.add(new Time(s, e));
		}
		Collections.sort(list);
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i = 0; i < list.size(); i++) {
			if(!pq.isEmpty() && pq.peek() <= list.get(i).s) {
				pq.poll();
			}
			pq.add(list.get(i).e);
		}
		System.out.println(pq.size());
	}
	public static class Time implements Comparable<Time> {
		public int s;
		public int e;
		public Time(int s, int e) {
			super();
			this.s = s;
			this.e = e;
		}
		@Override
		public int compareTo(Time o) {
			if(this.s == o.s) {
				return this.e - o.e;
			}
			return this.s - o.s;
		}
		
	}
}
