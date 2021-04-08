import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_4179 {
	static int R, C;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };
	static char[][] arr;
	static int[][] fire;
	static boolean[][] visit;
	static Queue<Pos> fq = new LinkedList<>();
	static Queue<Pos> jq = new LinkedList<>();

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		arr = new char[R][C];
		fire = new int[R][C];
		visit = new boolean[R][C];
		for (int i = 0; i < R; i++) {
			String temp = br.readLine();
			for (int j = 0; j < C; j++) {
				arr[i][j] = temp.charAt(j);
				if (arr[i][j] == 'F') {
					fq.offer(new Pos(i, j, 0));
				} else if (arr[i][j] == 'J') {
					jq.offer(new Pos(i, j, 0));
				}
			}
		}
		fbfs();
		int ans = jbfs();
		if (ans == -1) {
			System.out.println("IMPOSSIBLE");
		} else {
			System.out.println(ans);
		}
	}

	private static int jbfs() {
		while (!jq.isEmpty()) {
			Pos curr = jq.poll();
			for (int i = 0; i < 4; i++) {
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C) {
					return curr.cnt + 1;
				}
				if(arr[ny][nx] == '#') continue;
				if (!visit[ny][nx] && (curr.cnt + 1 < fire[ny][nx] || fire[ny][nx] == 0)) {
					visit[ny][nx] = true;
					fire[ny][nx] = fire[curr.y][curr.x] + 1;
					jq.offer(new Pos(ny, nx, curr.cnt + 1));
				}
			}
		}
		return -1;
	}

	private static void fbfs() {
		while (!fq.isEmpty()) {
			Pos curr = fq.poll();
			for (int i = 0; i < 4; i++) {
				int ny = curr.y + dy[i];
				int nx = curr.x + dx[i];
				if (ny < 0 || nx < 0 || ny >= R || nx >= C || arr[ny][nx] == '#')
					continue;
				if (fire[ny][nx] == 0) {
					fire[ny][nx] = fire[curr.y][curr.x] + 1;
					fq.offer(new Pos(ny, nx, curr.cnt + 1));
				}
			}
		}
	}

	static class Pos {
		int y;
		int x;
		int cnt;

		public Pos(int y, int x, int cnt) {
			super();
			this.y = y;
			this.x = x;
			this.cnt = cnt;
		}
	}
}
