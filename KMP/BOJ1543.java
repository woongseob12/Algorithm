import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ1543 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String origin = br.readLine();
		String search = br.readLine();
		System.out.println(kmp(origin, search));
	}

	private static int kmp(String o, String s) {
		if(o.length() < s.length()) {
			return 0;
		}
		int[] pi = makePi(s);
		
		int ans = 0;
		for(int i = 0, j = 0; i < o.length(); i++) {
			while(j > 0 && o.charAt(i) != s.charAt(j)) j = pi[--j];
			if(o.charAt(i) == s.charAt(j) && ++j == s.length()) {
				ans++;
				j = 0;
			}
		}
		return ans;
	}

	private static int[] makePi(String s) {
		int[] pi = new int[s.length()];
		
		for(int i = 1, j = 0; i < s.length(); i++) {
			while(j > 0 && s.charAt(i) != s.charAt(j)) {
				j = pi[--j];
			}
			if(s.charAt(i) == s.charAt(j)) pi[i] = ++j;
		}
		return pi;
	}
}
