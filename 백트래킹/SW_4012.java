package ssafy_algo_0219;

import java.io.*;
import java.util.*;

public class SW_4012 {
	static int N, T, ans;
	static int[][] arr;
	static int[] num, c1, c2;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			arr = new int[N][N];
			num = new int[N];
			c1 = new int[N/2];
			c2 = new int[N/2];
			for(int i = 0 ; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				for(int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			ans = 987654321;
			sol(0, 0, 0);
			sb.append("#" + tc + " " + ans + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}
	
	private static void sol(int cnt, int cnt1, int cnt2) {
		if(cnt1 > N/2 || cnt2 > N/2) {
			return;
		}
		if(cnt == N) {
			int idx1 = 0, idx2 = 0;
			for(int i = 0 ; i < N; i++) {
				if(num[i] == 1 && idx1 < N/2) c1[idx1++] = i;
				if(num[i] == 2 && idx2 < N/2) c2[idx2++] = i;
			}
			
			if(idx1 == N/2 && idx2 == N/2) {
				ans = Math.min(ans, cal());
			}
			return;
		}
		
		num[cnt] = 1;
		sol(cnt + 1, cnt1 + 1, cnt2);
		num[cnt] = 2;
		sol(cnt + 1, cnt1, cnt2 + 1);
		
	}
	
	private static int cal() {
		int a = 0, b = 0;
		for(int i = 0; i < N /2; i++) {
			for(int j = 0; j < N/ 2; j++) {
				if(i == j) continue;
				a += arr[c1[i]][c1[j]];
				b += arr[c2[i]][c2[j]];
			}
		}
		return Math.abs(a - b);
	}
}
