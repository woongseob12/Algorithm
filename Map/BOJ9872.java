import java.io.*;
import java.util.*;

public class BOJ9872 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> m = new HashMap<>();
        int ans = 0;
        while (n-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayList<String> cow = new ArrayList<>();
            while (st.hasMoreTokens()) {
                cow.add(st.nextToken());
            }
            Collections.sort(cow);
            String key = String.join(" ", cow);
            m.put(key, m.getOrDefault(key, 0) + 1);
            ans = Math.max(ans, m.get(key));
        }
        System.out.println(ans);
    }
}
