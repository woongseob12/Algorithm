import java.io.*;
import java.util.*;

public class BOJ13414 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int k = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());
        Set<String> s = new LinkedHashSet<>();
        for (int i = 0; i < l; i++) {
            String student = br.readLine();
            if (s.contains(student)) {
                s.remove(student);
            }
            s.add(student);
        }
        StringBuilder sb = new StringBuilder();
        Iterator<String> it = s.iterator();
        int loop = 0;
        while (it.hasNext()) {
            sb.append(it.next() + "\n");
            if (++loop == k)
                break;
        }

        System.out.println(sb);
    }
}
