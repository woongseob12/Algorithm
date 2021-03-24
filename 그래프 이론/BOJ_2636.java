package ssafyAlgo_0324;

import java.io.*;
import java.util.StringTokenizer;

public class BOJ_2636 {
	static int n, m;
	static int[][] arr;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());

		arr = new int[n][m];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int cnt = 0, time = 0;
		while (true) {
			outAir(0, 0);
			int temp = check();
			if(temp == 0) {
				break;
			}
			cnt = temp;
			originAir(0,0);
			time++;
		}
		System.out.println(time + "\n" + cnt);
	}

	private static void originAir(int y, int x) {
		arr[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}
			if (arr[ny][nx] == 2) {
				originAir(ny, nx);
			}
		}
	}

	private static void outAir(int y, int x) {
		arr[y][x] = 2;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
				continue;
			}
			if (arr[ny][nx] == 0) {
				outAir(ny, nx);
			}
		}
	}

	private static int check() {
		int ret = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 1) {
					continue;
				}
				ret++;
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny < 0 || nx < 0 || ny >= n || nx >= m) {
						continue;
					}
					if (arr[ny][nx] == 2) {
						arr[i][j] = 0;
						break;
					}
				}
			}
		}
		return ret;
	}
}
