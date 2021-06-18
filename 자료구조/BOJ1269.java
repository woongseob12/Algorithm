import java.io.*;
import java.util.*;

public class BOJ1269 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        Set<Integer> A = new HashSet<>();
        Set<Integer> B = new HashSet<>();

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < a; i++) {
            A.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < b; i++) {
            B.add(Integer.parseInt(st.nextToken()));
        }

        Iterator<Integer> it = A.iterator();
        int ans = 0;
        while (it.hasNext()) {
            if (!B.contains(it.next())) {
                ans++;
            }
        }
        it = B.iterator();
        while (it.hasNext()) {
            if (!A.contains(it.next())) {
                ans++;
            }
        }
        System.out.println(ans);
    }
}
