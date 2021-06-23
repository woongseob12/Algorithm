import java.io.*;
import java.util.*;

public class BOJ19583 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        String S = st.nextToken();
        String E = st.nextToken();
        String Q = st.nextToken();
        Map<String, Integer> m = new HashMap<>();
        System.out.println(S + E + Q);
        while (true) {
            String info = br.readLine();
            if (info == null || info.equals("")) {
                break;
            }
            st = new StringTokenizer(info);
            String time = st.nextToken();
            String name = st.nextToken();
            System.out.println("시간: " + time + " 이름: " + name);
            if (time.compareTo(S) <= 0) {
                m.put(name, 1);
            } else if (time.compareTo(E) >= 0 && time.compareTo(Q) <= 0 && m.containsKey(name)) {
                m.put(name, m.get(name) - 1);
            }
        }
        int ans = 0;
        for (Map.Entry<String, Integer> entry : m.entrySet()) {
            if (entry.getValue() == 0) {
                ans++;
            }
        }
        System.out.println(ans);
    }

}
