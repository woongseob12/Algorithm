package ssafy_0318;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SWEA_3289 {
	static int[] parent;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int TC = Integer.parseInt(br.readLine());
		for (int t = 1; t <= TC; t++) {
			sb.append("#" + t + " ");
			StringTokenizer st = new StringTokenizer(br.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			parent = new int[n + 1];
			for (int i = 1; i <= n; i++) {
				parent[i] = i;
			}

			for (int i = 0; i < 8; i++) {
				st = new StringTokenizer(br.readLine());
				int op = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if (op == 0) {
					unionParent(a, b);
				} else {
					if (findParent(a, b)) {
						sb.append(1);
					} else {
						sb.append(0);
					}
				}
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}

	private static int getParent(int x) {
		if (parent[x] == x)
			return x;
		else
			return parent[x] = getParent(parent[x]);
	}

	private static boolean findParent(int a, int b) {
		// TODO Auto-generated method stub
		a = getParent(a);
		b = getParent(b);
		if(a == b) return true;
		return false;
	}

	private static void unionParent(int a, int b) {
		// TODO Auto-generated method stub
		a = getParent(a);
		b = getParent(b);
		if (a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
}
