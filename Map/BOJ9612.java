import java.io.*;
import java.util.*;

public class BOJ9612 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Map<String, Integer> m = new TreeMap<>();
		while(n-- > 0) {
			String key = br.readLine();
			m.put(key, m.getOrDefault(key, 0) + 1);
		}
		
		int cnt = 0;
		String ans= "";
		for(Map.Entry<String, Integer> entry: m.entrySet()) {
			if(cnt <= entry.getValue()) {
				cnt = entry.getValue();
				ans = entry.getKey();
			}
		}
		System.out.println(ans + " " + cnt);
	}
}
