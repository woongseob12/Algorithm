import java.io.*;
import java.util.*;

public class BOJ7785 {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        TreeMap<String, String> m = new TreeMap<>(Collections.reverseOrder());
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String action = st.nextToken();
            if (action.equals("enter")) {
                m.put(name, action);
            } else {
                m.remove(name);
            }
        }
    }
}
