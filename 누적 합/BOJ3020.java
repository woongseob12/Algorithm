import java.io.*;
import java.util.*;

public class BOJ3020 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int[] down = new int[h + 1];
        int[] up = new int[h + 1];
        for (int i = 0; i < n / 2; i++) {
            int val = Integer.parseInt(br.readLine());
            down[val]++;
            val = Integer.parseInt(br.readLine());
            up[val]++;
        }

        int[] totD = new int[h + 1];
        int[] totU = new int[h + 1];

        for (int i = 1; i <= h; i++) {
            totD[i] = down[i] + totD[i - 1];
            totU[i] = up[i] + totU[i - 1];
        }

        int cnt = Integer.MAX_VALUE, ans = 0;
        for (int i = 1; i <= h; i++) {
            int temp = 0;

            temp += totD[h] - totD[i - 1];
            temp += totU[h] - totU[h - i];

            if (cnt > temp) {
                cnt = temp;
                ans = 1;
            } else if (cnt == temp) {
                ans++;
            }

        }
        System.out.println(cnt + " " + ans);
    }
}
