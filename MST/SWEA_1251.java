package ssafyAlgo_0324;

import java.io.*;
import java.util.*;

public class SWEA_1251 {
	static int N;
	static long[] x, y;
	static int[] parent;
	static double E;
	static long[][] arr;
	static PriorityQueue<Info> pq;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int TC = Integer.parseInt(br.readLine());
		for(int t = 1; t <= TC; t++) {
			N = Integer.parseInt(br.readLine());
			
			x = new long[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N; i++) {
				x[i] = Integer.parseInt(st.nextToken());
			}
			
			y = new long[N];
			st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N; i++) {
				y[i] = Integer.parseInt(st.nextToken());
			}
			
			parent = new int[N];
			for(int i = 0 ; i < N; i++) {
				parent[i] = i ;
			}
			
			E = Double.parseDouble(br.readLine());
			
			arr = new long[N][N];
			pq = new PriorityQueue<Info>();
			dist();
			int route = 0;
			long ans = 0;
			while(route != N - 1) {
				Info temp = pq.poll();
				if(find(temp.from) == find(temp.to)) continue;
				unionParnet(temp.from, temp.to);
				ans += temp.dist;
				route++;
			}
			sb.append("#" + t + " " + Math.round(ans * E) + "\n");
		}
		System.out.println(sb);
	}

	static class Info implements Comparable<Info>{
		long dist;
		int from;
		int to;
		public Info(long dist, int from, int to) {
			super();
			this.dist = dist;
			this.from = from;
			this.to = to;
		}
		@Override
		public int compareTo(Info o) {
			//return (int)(this.dist - o.dist);
			return Long.compare(this.dist, o.dist);
		}		
	}
	
	private static void dist() {
		for(int i = 0 ; i < N; i++) {
			for(int j = i + 1; j < N; j++) {
				arr[i][j] = arr[j][i] = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
				pq.offer(new Info(arr[i][j], i, j));
			}
		}
	}
	
	private static int find(int x) {
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	
	private static void unionParnet(int from, int to) {
		int a = find(from);
		int b = find(to);
		parent[a] = b;
	}
	
}
