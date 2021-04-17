import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_10159 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());

		int[][] arr = new int[N + 1][N + 1];
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			arr[a][b] = 1;
		}
		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 1; k <= N; k++) {
					if (arr[j][i] == 1 && arr[i][k] == 1) {
						arr[j][k] = 1;
					} else if (arr[i][j] == 1 && arr[k][i] == 1){
						arr[k][j] = 1;
					}
				}
			}
		}
		int ans = 0;
		for(int i = 1; i<= N; i++) {
			ans = 0;
			for(int j = 1; j <= N; j++) {
				if(i == j) continue;
				if(arr[i][j] == 0 && arr[j][i] == 0) {
					ans++;
				}
			}
			System.out.println(ans);
		}
	}
}
