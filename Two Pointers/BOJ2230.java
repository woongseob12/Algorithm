import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ2230 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int val = Integer.parseInt(br.readLine());
            list.add(val);
        }
        Collections.sort(list);
        int s = 0, e = 0;
        int ans = Integer.MAX_VALUE;
        while (s < n) {
            int diff = list.get(e) - list.get(s);
            System.out.println("s= " + s + " e = " + e + " diff = " + diff);
            if (e < n - 1 && diff < m) {
                e++;
            } else {
                if (diff >= m) {
                    ans = Math.min(ans, diff);
                }
                s++;
            }
        }
        System.out.println(ans);
    }
}
