import java.io.*;
import java.util.*;

public class BOJ1544 {
	static Set<String> s = new HashSet<>();
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0) {
			String word = br.readLine();
			if(noSame(word)) {
				s.add(word);
			}
		}
		System.out.println(s.size());
	}
	private static boolean noSame(String word) {
		int len = word.length();
		StringBuilder sb = new StringBuilder(word);
		while(len-- > 0) {
			if(s.contains(sb.toString())) {
				return false;
			}
			sb.append(sb.charAt(0));
			sb.delete(0, 1);
		}
		return true;
	}
}
