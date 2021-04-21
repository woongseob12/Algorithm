import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_3273 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0 ; i < n ; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		int x = Integer.parseInt(br.readLine());
		Arrays.sort(arr);
		
		int l = 0, r = n - 1, ans = 0;
		while(l < r) {
			if(arr[l] + arr[r] == x) {
				ans++;
				r--;
			} else if(arr[l] + arr[r] < x) {
				l++;
			} else {
				r--;
			}
		}
		System.out.println(ans);
	}
}
