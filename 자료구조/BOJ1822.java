import java.io.*;
import java.util.*;

public class BOJ1822 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        Set<Integer> A = new TreeSet<>();
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < a; i++) {
            A.add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < b; i++) {
            int val = Integer.parseInt(st.nextToken());
            if (A.contains(val)) {
                A.remove(val);
            }
        }
        StringBuilder sb = new StringBuilder();
        sb.append(A.size() + "\n");
        for (Integer val : A) {
            sb.append(val + " ");
        }
        System.out.println(sb);
    }
}
