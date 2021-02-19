package ssafy_algo_0219;

import java.io.*;
import java.util.*;

public class SW_3234 {
	static int N, ans;
	static int[] arr, num, idx;
	static boolean[] visit;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			arr = new int[N];
			num = new int[N];
			idx = new int[N];
			visit = new boolean[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			ans = 0;
			sol(0);
			sb.append("#" + tc + " " + ans + "\n");
		}
		bw.write(sb.toString());
		bw.flush();
		bw.close();
	}

	private static void sol(int cnt) {
		if (cnt == N) {
			//System.out.println(Arrays.toString(num));
			able(0, 0, 0);			
			return;
		}
		for(int i = 0 ; i < num.length; i++) {
			if(!visit[i]) {
				visit[i] = true;
				num[cnt] = arr[i];
				sol(cnt + 1);
				visit[i] = false;
			}
		}
	}

	private static void able(int cnt, int l, int r) {
		if(l < r) return;
		if(cnt == N) {
			ans++;
			return;
		}
		able(cnt + 1, l + num[cnt], r);
		able(cnt + 1, l, r + num[cnt]);
	}
}
