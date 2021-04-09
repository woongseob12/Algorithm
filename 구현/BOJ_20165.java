import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_20165 {
	static int dy[] = { 1, 0, -1, 0 };
	static int dx[] = { 0, 1, 0, -1 };

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int[][] arr = new int[N][M];
		boolean[][] fall = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int score = 0;
		for (int i = 0; i < R; i++) {
			// 공격수
			st = new StringTokenizer(br.readLine());
			int y = Integer.parseInt(st.nextToken()) - 1;
			int x = Integer.parseInt(st.nextToken()) - 1;
			char dir = st.nextToken().charAt(0);
			int d = -1;
			switch (dir) {
			case 'S':
				d = 0;
				break;
			case 'E':
				d = 1;
				break;
			case 'N':
				d = 2;
				break;
			case 'W':
				d = 3;
				break;
			}
			int ny = y - dy[d];
			int nx = x - dx[d];
			int cnt= arr[y][x];
			if(fall[y][x]) cnt = 0;
			fall[y][x] = true;
			int loop = 0;
			while(true) {
				ny += dy[d];
				nx += dx[d];
				if(ny < 0 || nx < 0 || ny >= N || nx >= M) break;
				cnt--;
				if(!fall[ny][nx]) {
					loop++;
					fall[ny][nx] = true;
					cnt = Math.max(cnt - 1, arr[ny][nx]);
				} 
				if(cnt == 0) break;
			}
			
			System.out.println(i + 1 +"번 라운드");
			for (int k = 0 ; k < N; k++) {
				for(int j = 0 ; j <M; j++) {
					if(fall[k][j]) {
						System.out.print("F ");
					} else {
						System.out.print("S ");
					}
				}
				System.out.println();
			}
			score += loop;
			// 수비수
			st = new StringTokenizer(br.readLine());
			y = Integer.parseInt(st.nextToken()) - 1;
			x = Integer.parseInt(st.nextToken()) - 1;
			fall[y][x] = false;
			System.out.println(i + 1 +"번 라운드");
			for (int k = 0 ; k < N; k++) {
				for(int j = 0 ; j <M; j++) {
					if(fall[k][j]) {
						System.out.print("F ");
					} else {
						System.out.print("S ");
					}
				}
				System.out.println();
			}
			
		}
		
		System.out.println(score);
		for (int i = 0 ; i < N; i++) {
			for(int j = 0 ; j <M; j++) {
				if(fall[i][j]) {
					System.out.print("F ");
				} else {
					System.out.print("S ");
				}
			}
			System.out.println();
		}
	}
}
