import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_16918 {
	static int R, C, N;
	static char[][] arr;
	static int[] dy = {1,0,-1,0};
	static int[] dx = {0,1,0,-1};
	static Queue<Pos> q = new LinkedList<Pos>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		arr= new char[R][C];
		for(int i = 0 ; i < R; i++) {
			String row = br.readLine();
			for(int j = 0; j < C; j++) {
				arr[i][j] = row.charAt(j);
			}
		}
		N--;
		while(N > 0) {
			N--;
			install();
			if(N <= 0) break;
			N--;
			boom();
		}
		
		for(int i = 0 ; i < R; i++) {
			for(int j = 0; j < C; j++) {
				sb.append(arr[i][j]);
			}
			sb.append('\n');
		}
		
		System.out.println(sb);
	}
	
	private static void boom() {
		while(!q.isEmpty()) {
			Pos temp = q.poll();
			arr[temp.y][temp.x] = '.';
			for(int i = 0; i < 4; i++) {
				int ny = temp.y + dy[i];
				int nx = temp.x + dx[i];
				if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
				arr[ny][nx] = '.';
			}
		}
		
	}
	
	private static void install() {
		for(int i = 0; i < R; i++) {
			for(int j = 0; j < C; j++) {
				if(arr[i][j] == '.') {
					arr[i][j] = 'O';
				}else {
					q.offer(new Pos(i,j));
				}
			}
		}
		
	}
	
	static class Pos{
		int y;
		int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
}
