import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_10216 {
	static int[] parent;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			int N = Integer.parseInt(br.readLine());
			parent = new int[N + 1];
			for (int i = 1; i < N; i++) {
				parent[i] = i;
			}
			Enemy[] e = new Enemy[N + 1];
			for (int i = 1; i <= N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int r = Integer.parseInt(st.nextToken());
				e[i] = new Enemy(y, x, r);
			}
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					double dist = Math
							.sqrt((e[i].y - e[j].y) * (e[i].y - e[j].y) + (e[i].x - e[j].x) * (e[i].x - e[j].x));
					if (e[i].r + e[j].r >= dist) {
						unionParent(i, j);
					}
				}
			}
			int ans = 0;
			boolean[] valid = new boolean[N + 1];
			for (int i = 1; i <= N; i++) {
				if(!valid[getParent(i)]) {
					valid[getParent(i)] = true;
					ans++;
				}
			}
			System.out.println(ans);
		}
	}

	private static void unionParent(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		if (a > b)
			parent[a] = b;
		else
			parent[b] = a;
	}

	private static int getParent(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = getParent(parent[x]);
	}

	static class Enemy {
		int y;
		int x;
		int r;

		public Enemy(int y, int x, int r) {
			super();
			this.y = y;
			this.x = x;
			this.r = r;
		}
	}
}
