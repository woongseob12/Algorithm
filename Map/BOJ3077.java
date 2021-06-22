import java.io.*;
import java.util.*;

public class BOJ3977 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int idx = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        Map<String, Integer> m = new HashMap<>();
        while (st.hasMoreTokens()) {
            m.put(st.nextToken(), ++idx);
        }
        ArrayList<String> list = new ArrayList<>();
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            list.add(st.nextToken());
        }
        int ans = 0;
        for (int i = 0; i < list.size() - 1; i++) {
            for (int j = i + 1; j < list.size(); j++) {
                if (m.get(list.get(i)) < m.get(list.get(j))) {
                    ans++;
                }
            }
        }
        int total = list.size() * (list.size() - 1) / 2;
        System.out.println(ans + "/" + total);
    }
}
