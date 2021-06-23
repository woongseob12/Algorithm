import java.io.*;
import java.util.*;

public class BOJ3022 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> m = new HashMap<>();
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            String name = br.readLine();
            m.put(name, m.getOrDefault(name, 0) + 1);
            int curr = m.get(name);
            if (curr > i - curr + 1) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
