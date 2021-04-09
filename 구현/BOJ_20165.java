import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_20165 {
	static int dy[] = { 1, 0, -1, 0 };
	static int dx[] = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int[][] arr = new int[N + 1][M + 1];
		boolean[][] fall = new boolean[N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 1; j <= M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}

		int score = 0;
		for (int i = 0; i < R; i++) {
			// 공격수
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken());
			int x = Integer.parseInt(st.nextToken());
			char dir = st.nextToken().charAt(0);
			int d = -1;
			switch (dir) {
			case 'S':
				d = 0;
				break;
			case 'E':
				d = 1;
				break;
			case 'N':
				d = 2;
				break;
			case 'W':
				d = 3;
				break;
			}

			int cnt = arr[y][x];
			int loop = 0;
			while (cnt > 0) {
				if (y < 1 || x < 1 || y > N || x > M)
					break;

				if (!fall[y][x]) {
					loop++;
					fall[y][x] = true;
					cnt = Math.max(cnt, arr[y][x]);
				}
				y += dy[d];
				x += dx[d];
				cnt--;
			}
			score += loop;
			// 수비수
			st = new StringTokenizer(br.readLine());
			y = Integer.parseInt(st.nextToken());
			x = Integer.parseInt(st.nextToken());
			fall[y][x] = false;

		}
		sb.append(score + "\n");
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (fall[i][j]) {
					sb.append("F ");
				} else {
					sb.append("S ");
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
