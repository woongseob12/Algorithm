import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_10476 {
	static int N, k;
	static int[][] arr;
	static int[][][] dp;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		arr = new int[N][2];
		int sum = 0;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
			sum += arr[i][0] + arr[i][1];
		}
		br.readLine();
		if (k == 0) {
			System.out.println(sum);
		} else {
			dp = new int[N][k + 1][3];
			// 0 : 1번 닫기 1: 2번 닫기 2: 모두 안 닫기
			dp[0][1][0] = arr[0][1];
			dp[0][1][1] = arr[0][0];
			dp[0][0][2] = arr[0][0] + arr[0][1];

			for (int i = 1; i < N; i++) {
				for (int j = 0; j <= k; j++) {
					if (j >= 1) {
						dp[i][j][0] = Math.max(dp[i - 1][j - 1][0], dp[i - 1][j - 1][2]) + arr[i][1];
						dp[i][j][1] = Math.max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]) + arr[i][0];
					}
					if (i >= j) {
						dp[i][j][2] = Math.max(dp[i - 1][j][0], Math.max(dp[i - 1][j][1], dp[i - 1][j][2])) + arr[i][0]
								+ arr[i][1];
					}
				}
			}
			System.out.println(Math.max(dp[N - 1][k][0], Math.max(dp[N - 1][k][1], dp[N - 1][k][2])));
		}
	}
}
