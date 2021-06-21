import java.io.*;
import java.util.*;

public class BOJ2358 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Map<Integer, ArrayList<Integer>> x = new HashMap<>();
		Map<Integer, ArrayList<Integer>> y = new HashMap<>();
		int n = Integer.parseInt(br.readLine());
		while(n-->0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			if(!x.containsKey(a)) {
				ArrayList<Integer> list = new ArrayList<>();
				list.add(b);
				x.put(a, list);
			} else {
				ArrayList<Integer> list = x.get(a);
				list.add(b);
				x.put(a, list);
			}
			if(!y.containsKey(b)) {
				ArrayList<Integer> list = new ArrayList<>();
				list.add(a);
				y.put(b, list);
			} else {
				ArrayList<Integer> list = y.get(b);
				list.add(a);
				y.put(b, list);
			}
		}
		int ans = 0;
		for(Map.Entry<Integer, ArrayList<Integer>> entry: x.entrySet()) {
			if(entry.getValue().size() > 1) {
				ans++;
			}
		}
		for(Map.Entry<Integer, ArrayList<Integer>> entry: y.entrySet()) {
			if(entry.getValue().size() > 1) {
				ans++;
			}
		}
		System.out.println(ans);
	}
}
