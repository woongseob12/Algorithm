import java.io.*;
import java.util.StringTokenizer;

public class BOJ_2512 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());

		int[] arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		long sum = 0, maxCost = 0;
		for (int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			maxCost = Math.max(maxCost, arr[i]);
			sum += arr[i];
		}
		int M = Integer.parseInt(br.readLine());
		if (sum <= M) {
			System.out.println(maxCost);
		} else {
			int l = 0, r = M, ans = 0;
			while (l <= r) {
				int mid = (l + r) / 2;
				long total = 0;
				for(int i = 0 ; i < N; i++) {
					total += Math.min(mid, arr[i]);
				}
				if (total <= M) {
					ans = mid;
					l = mid + 1;
				} else {
					r = mid - 1;
				}
			}
			System.out.println(ans);
		}
	}
}
