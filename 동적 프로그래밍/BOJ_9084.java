import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_9084 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int T= Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(T-- > 0) {
			int N =Integer.parseInt(br.readLine());
			int[] money = new int[N];
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++) {
				money[i] = Integer.parseInt(st.nextToken());
			}

			int M = Integer.parseInt(br.readLine());
			int[] dp = new int[M + 1];
			dp[0] = 1;
			
			for(int i = 0; i < N; i++) {
				for(int j = money[i]; j <= M; j++) {
					dp[j] += dp[j - money[i]];	
				}
			}
			sb.append(dp[M] + "\n");
		}
		System.out.println(sb);
	}
}
