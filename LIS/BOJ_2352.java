import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class BOJ_2352 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < n; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		List<Integer> list = new ArrayList<Integer>();
		list.add(arr[0]);
		for(int i = 1; i < n; i++) {
			if(list.get(list.size() - 1) < arr[i]) {
				list.add(arr[i]);
			} else {
				int l = 0, r = list.size() - 1;
				while(l < r) {
					int mid = (l + r) / 2;
					if(list.get(mid) < arr[i]) {
						l = mid + 1;
					} else {
						r = mid;
					}
				}
				list.set(r, arr[i]);
			}
		}
		System.out.println(list.size());
	}
}
