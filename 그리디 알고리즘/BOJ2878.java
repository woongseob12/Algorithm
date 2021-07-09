import java.io.*;
import java.util.*;

public class BOJ2878 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        Integer[] haveCandy = new Integer[n];
        long total = 0;
        for (int i = 0; i < n; i++) {
            haveCandy[i] = Integer.parseInt(br.readLine());
            total += haveCandy[i];
        }
        Arrays.sort(haveCandy);

        long rest = total - m;

        long ans = 0;
        for (int i = 0; i < n; i++) {
            long bombDisposal = Math.min(haveCandy[i], rest / (n - i));
            ans += bombDisposal * bombDisposal;
            rest -= bombDisposal;
        }
        System.out.println(ans);
    }
}
