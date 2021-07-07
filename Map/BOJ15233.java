import java.io.*;
import java.util.*;

public class BOJ15233 {

	static int[] score = new int[2];
	static Map<String, Integer> team = new HashMap<>();
	public static void main(String[] args) throws IOException {
		input();
		output();
	}

	private static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			team.put(st.nextToken(), 0);
		}
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			team.put(st.nextToken(), 1);
		}
		st = new StringTokenizer(br.readLine());
		while(st.hasMoreTokens()) {
			score[team.get(st.nextToken())]++;
		}
	}

	private static void output() {
		if(score[0] < score[1]) {
			System.out.println("B");
		}else if(score[0] == score[1]) {
			System.out.println("TIE");
		}else {
			System.out.println("A");
		}
	}
	
}
