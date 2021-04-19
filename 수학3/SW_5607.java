import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW_5607 {
	static final int MOD = 1234567891;
	static int n, r;
	static long fact[];

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		fact = new long[1000001];
		fact[0] = 1;
		for (int i = 1; i <= 1000000; i++) {
			fact[i] = (fact[i - 1] * i) % MOD;
		}
		
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			n = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());

			long temp = ((fact[n - r] % MOD ) * (fact[r]%MOD))%MOD;
			long ans = fact[n];
			ans = fact[n] * cal(fact[n - r], MOD - 2) % MOD;
			ans = ans * cal(fact[r], MOD - 2) % MOD;
			
			System.out.println("#" + t + " " + ans + "\n");
		}
	}

	private static long cal(long n, int x) {
		if (x == 0)
			return 1;

		long ret = cal(n, x / 2);
		if (x % 2 == 0)
			return ((ret % MOD) * (ret % MOD)) % MOD;
		else
			return (((ret * n) % MOD) * (ret % MOD)) % MOD;
	}
}
