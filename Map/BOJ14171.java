import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Map<String, Integer> m = new HashMap<>();
        String[] arr = new String[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String key = st.nextToken();
            key = key.substring(0, 2);
            String value = st.nextToken();
            arr[i] = key + value;
            m.put(arr[i], m.getOrDefault(arr[i], 0) + 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            String code = arr[i].substring(2, 4) + arr[i].substring(0, 2);
            if (!arr[i].substring(2, 4).equals(code.substring(2, 4)) && m.containsKey(code)) {
                ans += m.get(code);
            }
        }
        ans /= 2;
        System.out.println(ans);
    }
}
