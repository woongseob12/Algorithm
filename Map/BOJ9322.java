import java.io.*;
import java.util.*;

public class BOJ9322 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(tc-- > 0) {
			@SuppressWarnings("unused")
			int n = Integer.parseInt(br.readLine());
			Map<String, Integer> m = new HashMap<>(); 
			StringTokenizer st = new StringTokenizer(br.readLine());
			int idx = 0;
			while(st.hasMoreTokens()) {
				m.put(st.nextToken(), ++idx);
			}
			ArrayList<Integer> list = new ArrayList<>();
			st = new StringTokenizer(br.readLine());
			while(st.hasMoreTokens()) {
				int val = m.get(st.nextToken());
				list.add(val);
			}
			
			Map<Integer, String> res = new TreeMap<>();
			st = new StringTokenizer(br.readLine());
			idx = 0;
			while(st.hasMoreTokens()) {
				res.put(list.get(idx++),st.nextToken());
			}
			
			for(Map.Entry<Integer, String> entry: res.entrySet()) {
				sb.append(entry.getValue() + " ");
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
