package Week3;

import java.io.*;

public class SW_2805_2 {
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
				map[i][0] = s.charAt(0) - '0';
				for(int j = 1 ; j < N; j++) {
					map[i][j] = map[i][j-1] + (s.charAt(j) - '0');
				}
			}
			
			// 풀이
			int start = N / 2, ans = 0;
			for(int i = 0; i < N ;i++) {
				
				if(start > 0) {
					ans += map[i][N - start - 1] - map[i][start - 1];
				}
				else if(start == 0) {
					ans += map[i][N - 1];
				}
				else {
					ans += map[i][N - (start * -1) - 1] - map[i][(start * -1) - 1];
				}
				start--;
			
			}
			// 출력
			sb.append("#" + tc + " " + ans + '\n');
		}
		System.out.println(sb);
	}
}
