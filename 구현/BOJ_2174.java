import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2174 {
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, -1, 0, 1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int A = Integer.parseInt(st.nextToken());
		int B = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[][] arr = new int[B + 1][A + 1];

		// 1. 로봇 위치 설정 구하기
		Robot[] r = new Robot[N + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			char dir = st.nextToken().charAt(0);
			switch (dir) {
			case 'N':
				r[i] = new Robot(y, x, 0);
				break;
			case 'W':
				r[i] = new Robot(y, x, 1);
				break;
			case 'S':
				r[i] = new Robot(y, x, 2);
				break;
			case 'E':
				r[i] = new Robot(y, x, 3);
				break;
			default:
				break;
			}
			arr[y][x] = i;
		}
		// 2. 로봇 명령 수행하기
		boolean flag = true;
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int idx = Integer.parseInt(st.nextToken());
			char op = st.nextToken().charAt(0);
			int loop = Integer.parseInt(st.nextToken());
			if (op == 'L') {
				loop %= 4;
				int temp = r[idx].dir;
				temp = (temp + loop) % 4;
				r[idx].dir = temp;
			} else if (op == 'R') {
				loop %= 4;
				int temp = r[idx].dir;
				temp = (temp - loop + 4) % 4;
				r[idx].dir = temp;
			} else {
				int dir = r[idx].dir;
				for (int j = 1; j <= loop; j++) {
					int ny = r[idx].y + dy[dir] * j;
					int nx = r[idx].x + dx[dir] * j;
					if (ny < 1 || nx < 1 || ny > B || nx > A) {
						sb.append("Robot " + idx + " crashes into the wall\n");
						flag = false;
						break;
					}
					if (arr[ny][nx] != 0) {
						sb.append("Robot " + idx + " crashes into robot " + arr[ny][nx] + "\n");
						flag = false;
						break;
					}
					if (j == loop) {
						arr[r[idx].y][r[idx].x] = 0;
						arr[ny][nx] = idx;
						r[idx].y = ny;
						r[idx].x = nx;
					}
				}
				if (!flag)
					break;
			}
		}
		if (flag)
			sb.append("OK\n");
		System.out.println(sb);
	}

	static class Robot {
		int y;
		int x;
		int dir;

		public Robot(int y, int x, int dir) {
			super();
			this.y = y;
			this.x = x;
			this.dir = dir;
		}
	}
}