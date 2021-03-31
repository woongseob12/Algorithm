import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_17071 {
	static final int MAX = 500000;
	static int N, K;
	static int[][] visit = new int[MAX + 1][2];
	static int[] d = {1, -1, 0};
	static int[] dm = {1, 1, 2};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		for(int i = 0 ; i <= MAX; i++) {
			Arrays.fill(visit[i], -1);
		}
		System.out.println(bfs());
	}
	
	private static int bfs() {
		Queue<Info> q = new LinkedList<Info>();
		q.offer(new Info(N, 0));
		while(!q.isEmpty()) {
			Info curr = q.poll();
			
			if(curr.pos < 0 || curr.pos > MAX) continue;
			if(visit[curr.pos][curr.time % 2] != -1) continue;
			visit[curr.pos][curr.time % 2] = curr.time;
			q.offer(new Info(curr.pos + 1, curr.time + 1));
			q.offer(new Info(curr.pos - 1, curr.time + 1));
			q.offer(new Info(curr.pos * 2, curr.time + 1));
		}
		
		int turn = 0;
		while(K <= MAX) {
			if(visit[K][turn % 2] != -1 && visit[K][turn % 2] <= turn) {
				return turn;
			}
			turn++;
			K += turn;
		}
		return -1;
	}
	
	static class Info{
		int pos;
		int time;
		public Info(int pos, int time) {
			super();
			this.pos = pos;
			this.time = time;
		}
	}
}
