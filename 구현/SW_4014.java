import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW_4014 {
	static int N, X;
	static int[][] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			arr = new int[N][N];
			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < N; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			int ans = 0;
			for (int i = 0; i < N; i++) {
				ans += row(i);
			}for (int i = 0; i < N; i++) {
				ans += col(i);
			}
			sb.append("#" + t + " " + ans + "\n");
		}
		System.out.println(sb);
	}

	private static int col(int i) {
		int[] temp = new int[N];
		boolean[] install = new boolean[N];
		for(int idx = 0; idx < N; idx++) {
			temp[idx] = arr[idx][i];
		}

		// 상 > 하
		int h = temp[0];
		int cnt = 1;
		for (int s = 1; s < N; s++) {
			if (h == temp[s]) {
				cnt++;
			} else if(Math.abs(temp[s] - h) == 1) {
				if (h < temp[s] && cnt < X) {return 0;}
				else if (h < temp[s] && cnt >= X) {
					for(int len = 0; len < X; len++) {
						install[s- 1 - len] = true;
					}
				}
				h = temp[s];
				cnt = 1;
			} else {
				return 0;
			}
		}
		
		h = temp[N - 1];
		cnt = 1;
		for (int s = N - 2; s >= 0; s--) {
			if (h == temp[s]) {
				cnt++;
			} else if(Math.abs(temp[s] - h) == 1) {
				if (h < temp[s] && cnt < X) {return 0;}
				else if (h < temp[s] && cnt >= X) {
					for(int len = 0; len < X; len++) {
						if(install[s + 1 + len]) {return 0;}
					}
				}
				h = temp[s];
				cnt = 1;
			} else {
				return 0;
			}
		}
		//System.out.println("col :" + i);
		return 1;
	}

	private static int row(int i) {
		int[] temp = new int[N];
		boolean[] install = new boolean[N];
		for(int idx = 0; idx < N; idx++) {
			temp[idx] = arr[i][idx];
		}
		// 좌 > 우
		int h = temp[0];
		int cnt = 1;
		for (int s = 1; s < N; s++) {
			if (h == temp[s]) {
				cnt++;
			} else if(Math.abs(temp[s] - h) == 1) {
				if (h < temp[s] && cnt < X) {return 0;}
				else if (h < temp[s] && cnt >= X) {
					for(int len = 0; len < X; len++) {
						install[s- 1 - len] = true;
					}
				}
				h = temp[s];
				cnt = 1;
			} else {
				return 0;
			}
		}
		// 우 > 좌
		h = temp[N - 1];
		cnt = 1;
		for (int s = N - 2; s >= 0; s--) {
			if (h == temp[s]) {
				cnt++;
			} else if(Math.abs(temp[s] - h) == 1) {
				if (h < temp[s] && cnt < X) {return 0;}
				else if (h < temp[s] && cnt >= X) {
					for(int len = 0; len < X; len++) {
						if(install[s + 1 + len]) {return 0;}
					}
				}
				h = temp[s];
				cnt = 1;
			} else {
				return 0;
			}
		}
		//System.out.println("row :" + i);
		return 1;
	}

}
