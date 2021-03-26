import java.io.*;
import java.util.StringTokenizer;

public class BOJ_1072 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long X = Long.parseLong(st.nextToken());
		long Y = Long.parseLong(st.nextToken());
		int Z = (int) (100 * Y / X);

		int l = 0, r = 1000000000, ans = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			int temp = (int) (100 * (Y + mid) / (X + mid));
			if (temp != Z) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		System.out.println(ans);
	}
}
