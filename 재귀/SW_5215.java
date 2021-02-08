package ssafy_algo_0208;

import java.io.*;
import java.util.StringTokenizer;

public class SW_5215 {
	static int TC, num, cal, ans;
	static int[] taste, calory;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		TC = Integer.parseInt(br.readLine());
		for(int t = 1; t <= TC; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			num = Integer.parseInt(st.nextToken());
			cal = Integer.parseInt(st.nextToken());
			
			taste = new int[num];
			calory = new int[num];
			for(int i = 0 ; i < num; i++) {
				st = new StringTokenizer(br.readLine());
				taste[i] = Integer.parseInt(st.nextToken());
				calory[i] = Integer.parseInt(st.nextToken());
			}
			// 풀이
			ans = 0;
			recursive(0, 0, 0);
			// 출력
			sb.append("#" + t + " " + ans + "\n");
		}
		System.out.println(sb);
		
		
		
	}
	
	public static void recursive(int cnt, int t, int c) {
		if(cnt == num) {
			if(ans < t && c <= cal) {
				ans = t;
			}
			return;
		}
		recursive(cnt + 1, t + taste[cnt], c + taste[cnt]);
		recursive(cnt + 1, t, c);
	}
}
