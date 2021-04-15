import java.io.*;
import java.util.*;

public class BOJ_15961 {
	static int N, d, k, c;
	static int[] arr, eat;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		d = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		arr = new int[N + k];
		for(int i = 0 ; i < N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		for (int i = 0; i < k; i++) {
           	arr[N + i] = arr[i];
        }
		
		int ans = 0;
		int l = 0, r = 0;
		// 백준 시간초과 X, 정올 시간초과 O
		/*Map<Integer, Integer> m = new HashMap<>();
		while(l != N) {
			if(r - l < k) {
				if(m.containsKey(arr[r])) {
					m.put(arr[r], m.get(arr[r]) + 1);
				} else {
					m.put(arr[r], 1);					
				}
				r++;
			} else if(r - l == k) {
				m.put(c, 1);
				ans = Math.max(ans, m.size());
				m.put(arr[l], m.get(arr[l]) - 1);
				if(m.get(arr[l]) == 0) {
					m.remove(arr[l]);
				}
				l++;
			}
		}*/
		// 두 싸이트 모두 시간초과 나지 않는 코드
		eat = new int[d + 1];
		int temp = 0;
		while(l != N) {
			if(r - l < k) {
				eat[arr[r]]++;
				if(eat[arr[r]] == 1) temp++;
				r++;
			} else if(r - l == k) {
				if(eat[c] == 0) temp++;
				ans = Math.max(ans, temp);
				if(eat[c] == 0) temp--;
				eat[arr[l]]--;
				if(eat[arr[l]] == 0) temp--;
				l++;
			}
		}
		System.out.println(ans);
	}
}
