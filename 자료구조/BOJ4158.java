import java.io.*;
import java.util.*;

public class BOJ4158 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        while (true) {
            Set<Integer> s = new HashSet<>();
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) {
                break;
            }
            while (n-- > 0) {
                int val = Integer.parseInt(br.readLine());
                s.add(val);
            }
            int ans = 0;
            while (m-- > 0) {
                int val = Integer.parseInt(br.readLine());
                if (s.contains(val)) {
                    ans++;
                }
            }
            sb.append(ans + "\n");
        }
        System.out.println(sb);
    }
}
