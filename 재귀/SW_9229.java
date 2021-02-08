package ssafy_algo_0208;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW_9229 {
	static int N, M, ans;
	static int[] cookie;
	public static void main(String[] args) throws NumberFormatException, IOException {
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int TC = Integer.parseInt(br.readLine());
		for(int t = 1; t <= TC; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			cookie = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0 ; i < N; i++) {
				 cookie[i] = Integer.parseInt(st.nextToken());
			}
			// 풀이
			ans = -1;
			comb(0, 0, 0);
			// 출력
			sb.append("#" + t + " " + ans + "\n");
		}
		System.out.println(sb);
	}
	
	public static void comb(int cnt, int idx, int val) {
		if(cnt == 2) {
			if(ans < val && val <= M) {
				ans = val;
			}
			return;
		}
		if(idx > N || val > M ) return;
		comb(cnt + 1, idx + 1, val + cookie[idx]);
		comb(cnt, idx + 1, val);
	}
}
