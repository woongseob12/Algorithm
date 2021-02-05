package ssafy_algo_0205;

import java.io.*;
import java.util.*;

public class SW_3499 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			int N = Integer.parseInt(br.readLine());
			Queue<String> l = new LinkedList<String>();
			Queue<String> r = new LinkedList<String>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				if (N % 2 == 0) {
					if(i < N / 2) {
						l.offer(st.nextToken());
					}else {
						r.offer(st.nextToken());
					}
				} else {
					if(i <= N / 2) {
						l.offer(st.nextToken());
					}else {
						r.offer(st.nextToken());
					}
				}
			}

			sb.append("#" + tc + " ");
			while(!r.isEmpty()) {
				sb.append(l.poll() + " " + r.poll() + " ");
			}
			if(N % 2 == 1) {
				sb.append(l.poll());
			}
			sb.append('\n');
		}
		System.out.println(sb);
	}
}
