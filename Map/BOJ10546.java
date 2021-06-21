import java.io.*;
import java.util.*;

public class BOJ10546 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Map<String,Integer> m = new HashMap<>();
		for(int i = 0 ; i < n; i++) {
			String key = br.readLine();
			m.put(key, m.getOrDefault(key, 0) + 1);
		}
		for(int i = 0 ; i < n - 1; i++) {
			String key = br.readLine();
			m.put(key, m.get(key) - 1);
		}
		for(Map.Entry<String, Integer> entry: m.entrySet()) {
			if(entry.getValue() != 0) {
				System.out.println(entry.getKey());
				break;
			}
		}
	}
}
