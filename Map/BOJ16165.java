import java.io.*;
import java.util.*;

public class BOJ16165 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Map<String, String> groupName = new HashMap<>();
        Map<String, Set<String>> memberName = new HashMap<>();

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            String group = br.readLine();
            int num = Integer.parseInt(br.readLine());
            Set<String> list = new TreeSet<>();
            for (int j = 0; j < num; j++) {
                String member = br.readLine();
                list.add(member);
                groupName.put(member, group);
            }
            memberName.put(group, list);
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            String key = br.readLine();
            int val = Integer.parseInt(br.readLine());
            if (val == 1) {
                sb.append(groupName.get(key) + "\n");
            } else {
                Iterator<String> it = memberName.get(key).iterator();
                while (it.hasNext()) {
                    sb.append(it.next() + "\n");
                }
            }
        }
        System.out.println(sb);
    }
}
