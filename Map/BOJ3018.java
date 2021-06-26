import java.io.*;
import java.util.*;

public class BOJ3018 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Map<Integer, Set<Integer>> m = new TreeMap<>();
		for(int i = 1; i <= n; i++) {
			m.put(i, new HashSet<>());
		}
		int e = Integer.parseInt(br.readLine());
		int song = 0;
		while(e-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int person = Integer.parseInt(st.nextToken());
			int[] arr = new int[person];
			for(int i = 0; i < person; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(arr);
			if(arr[0] == 1) {
				while(person-- > 0) {
					for(int key: arr) {
						Set<Integer> temp = m.get(key);	
						temp.add(song);
					}
					song++;
				}
			} else {
				Set<Integer> temp = new HashSet<>();
				for(int key: arr) {
					Iterator<Integer> it = m.get(key).iterator();
					while(it.hasNext()) {
						temp.add(it.next());
					}
				}
				
				for(int key: arr) {
					Iterator<Integer> it = temp.iterator();
					while(it.hasNext()) {
						m.get(key).add(it.next());
					}
				}
			}
		}
		int size = m.get(1).size();
		for(Map.Entry<Integer, Set<Integer>> entry: m.entrySet()) {
			if(entry.getValue().size() == size) {
				System.out.print(entry.getKey() + " ");
			}
		}
	}
}
