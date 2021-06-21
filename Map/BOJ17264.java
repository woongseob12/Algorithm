import java.io.*;
import java.util.*;

public class BOJ17264 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int W = Integer.parseInt(st.nextToken());
		int L = Integer.parseInt(st.nextToken());
		int G = Integer.parseInt(st.nextToken());
		Map<String,Integer> m = new HashMap<>();
		while(p-- > 0) {
			st = new StringTokenizer(br.readLine());
			String name = st.nextToken();
			String result = st.nextToken();
			if(result.equals("W")) {
				m.put(name, W);
			} else {
				m.put(name, L * (-1));
			}
		}
		int score = 0;
		while(n-- > 0) {
			String name = br.readLine();
			if(!m.containsKey(name)) {
				score -= L;
			} else {
				score += m.get(name);
			}
			if(score >= G) {break;}
			if(score < 0) {score = 0;}
		}
		if(score >= G) {
			System.out.println("I AM NOT IRONMAN!!");
		} else {
			System.out.println("I AM IRONMAN!!");
		}
	}
}
