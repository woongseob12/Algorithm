import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class SW_5656{
	static int N, W, H, answer;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };
	static int[] comb;
	static int[][] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			W = Integer.parseInt(st.nextToken());
			H = Integer.parseInt(st.nextToken());
			arr = new int[H][W];
			for (int i = 0; i < H; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < W; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			comb = new int[N];
			answer = Integer.MAX_VALUE;
			makecomb(0);
			sb.append("#"+t+" " + answer + "\n");
		}
		System.out.println(sb);
	}

	private static void makecomb(int cnt) {
		if (cnt == N) {
			cal();
			return;
		}

		for (int i = 0; i < W; i++) {
			comb[cnt] = i;
			makecomb(cnt + 1);
		}

	}

	private static void cal() {
		int[][] copy = new int[H][W];
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				copy[i][j] = arr[i][j];
			}
		}
		
		Queue<Block> q = new LinkedList<>();
		for(int i = 0 ; i < N; i++) {
			int col = comb[i];
			int h = 0;
			while(h != H && copy[h][col] == 0) {
				h++;
			}
			
			if(h != H) {
				q.add(new Block(h, col, copy[h][col]));
				while(!q.isEmpty()) {
					Block temp = q.poll();
					copy[temp.y][temp.x] = 0;
					for(int d = 0 ; d < 4; d++) {
						for(int len = 1; len <= temp.cnt - 1 ; len++) {
							int ny = temp.y + dy[d] * len;
							int nx = temp.x + dx[d] * len;
							if(ny < 0 || nx < 0 || ny >= H || nx >= W || copy[ny][nx] == 0) continue;
							if(copy[ny][nx] != 0) {
								q.add(new Block(ny, nx, copy[ny][nx]));
								copy[ny][nx] = 0;
							}
						}
					}
				}
			}
			int[][] re = new int[H][W];
			int cIdx = 0;
			while(cIdx != W) {
				int idx = H - 1;
				for(int rIdx = H - 1; rIdx >= 0; rIdx--) {
					if(copy[rIdx][cIdx] != 0) {
						re[idx--][cIdx] = copy[rIdx][cIdx];
					}
				}
				cIdx++;
			}
			copy = re;
		}
		
		int ans = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if(copy[i][j] != 0) {
					ans++;
				}
			}
		}
		answer = Math.min(answer, ans);
	}

	static class Block {
		int y;
		int x;
		int cnt;

		public Block(int y, int x, int cnt) {
			super();
			this.y = y;
			this.x = x;
			this.cnt = cnt;
		}

	}
}
