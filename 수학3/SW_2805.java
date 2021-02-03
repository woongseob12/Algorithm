package Week3;

import java.io.*;

public class SW_2805 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			// 입력
			int N = Integer.parseInt(br.readLine());
			int[][] map = new int[N][N];
			for(int i = 0 ; i < N; i++) {
				String s = br.readLine();
				for(int j = 0 ; j < N; j++) {
					map[i][j] =s.charAt(j) - '0';
				}
			}
			// 풀이
			int start = N / 2, ans = 0;
			for(int i = 0; i < N ;i++) {
				if(start < 0) {
					for(int j = start * -1; j < N - (start * -1); j++) {
						ans += map[i][j];
					}
				}
				else {
					for(int j = start; j < N - start; j++) {
						ans += map[i][j];
					}
				}
				start--;
			}
			// 출력
			sb.append("#" + tc + " " + ans + '\n');
		}
		System.out.println(sb);
	}
}
