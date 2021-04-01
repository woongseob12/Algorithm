import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class BOJ_15591 {
	static int N, Q, cnt;
	static ArrayList<Info>[] graph;
	static boolean[] visit;
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		N= Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		graph = new ArrayList[N + 1];
		for(int i = 1; i <= N; i++) {
			graph[i] = new ArrayList<Info>();
		}
		
		for(int i = 0 ; i < N - 1; i++) {
			st = new StringTokenizer(br.readLine());
			int p = Integer.parseInt(st.nextToken());
			int q = Integer.parseInt(st.nextToken());
			int r = Integer.parseInt(st.nextToken());
			graph[p].add(new Info(q, r));
			graph[q].add(new Info(p, r));
		}
		
		for(int i = 0 ; i < Q; i++) {
			st = new StringTokenizer(br.readLine());
			int k = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			visit = new boolean[N + 1];
			cnt = 0;
			visit[v] = true;
			dfs(k, v);
			sb.append(cnt + "\n");
		}
		System.out.println(sb);
	}

	private static void dfs(int k, int v) {
		for(int i = 0; i < graph[v].size(); i++) {
			int next = graph[v].get(i).next;
			if(!visit[next] && graph[v].get(i).cost >= k) {
				visit[next] = true;
				cnt++;
				dfs(k, next);
			}
		}
	}
	
	static class Info{
		int next;
		int cost;
		public Info(int next, int cost) {
			super();
			this.next = next;
			this.cost = cost;
		}
	}
}
