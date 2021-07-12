import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ1719 { 
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] cost = new int[n + 1][n + 1];
		int[][] next = new int[n + 1][n + 1];

		for(int[] row: cost) {
			Arrays.fill(row, 999999);
		}
		
		for(int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int time = Integer.parseInt(st.nextToken());
			cost[a][b] = cost[b][a] = time;
			next[a][b] = b;
			next[b][a] = a;
		}
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 1; k <= n; k++) {
					if(cost[j][k] > cost[j][i] + cost[i][k]) {
						cost[j][k] = cost[j][i] + cost[i][k];
						next[j][k] = next[j][i];
					}
				}
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) {
					sb.append("- ");
				} else {
					sb.append(next[i][j] + " ");
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
