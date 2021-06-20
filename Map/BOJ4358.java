import java.io.*;
import java.util.*;

public class BOJ4358 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Map<String, Integer> m = new TreeMap<>();
        int total = 0;
        while (true) {
            String key = br.readLine();
            if (key == null || key.equals("")) {
                break;
            }
            if (!m.containsKey(key)) {
                m.put(key, 1);
            } else {
                m.put(key, m.get(key) + 1);
            }
            total++;
        }
        for (Map.Entry<String, Integer> entry : m.entrySet()) {
            double res = entry.getValue() / (double) total;
            System.out.println(entry.getKey() + " " + String.format("%.4f", res));
        }
    }
}
