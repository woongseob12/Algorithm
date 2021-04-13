import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2564 {
	static int N, M, store;
	static int[][] pos;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		store = Integer.parseInt(br.readLine());
		pos = new int[store + 1][2];
		for (int i = 0; i < store + 1; i++) {
			st = new StringTokenizer(br.readLine());
			int dir = Integer.parseInt(st.nextToken());
			int dist = Integer.parseInt(st.nextToken());
			if(dir == 2) dist = M + N + (M - dist);
			else if(dir == 3) dist = M + N + M + (N - dist);
			else if(dir == 4) dist = M + dist;
			pos[i][0] = dir;
			pos[i][1] = dist;
		}

		int sum = 0;
		for (int i = 0; i < store; i++) {
			int diff = Math.abs(pos[i][1] - pos[store][1]);
			sum += Math.min(2*M + 2*N - diff, diff);
		}
		System.out.println(sum);
	}
}
