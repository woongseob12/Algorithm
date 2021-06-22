import java.io.*;
import java.util.*;

public class BOJ12906 {
    static Set<String> visit = new HashSet<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        String A = "";
        if (a != 0) {
            A = st.nextToken();
        }
        st = new StringTokenizer(br.readLine());
        int b = Integer.parseInt(st.nextToken());
        String B = "";
        if (b != 0) {
            B = st.nextToken();
        }
        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        String C = "";
        if (c != 0) {
            C = st.nextToken();
        }
        System.out.println(bfs(A, B, C));

    }

    private static int bfs(String A, String B, String C) {
        Queue<Info> q = new LinkedList<>();
        q.offer(new Info(A, B, C, 0));
        while (!q.isEmpty()) {
            Info curr = q.poll();
            if (finish(curr)) {
                return curr.cnt;
            }
            if (curr.A.length() > 0) {
                char temp = curr.A.charAt(curr.A.length() - 1);
                String s = curr.A.substring(0, curr.A.length() - 1) + " " + curr.B + temp + " " + curr.C;
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A.substring(0, curr.A.length() - 1), curr.B + temp, curr.C, curr.cnt + 1));
                    visit.add(s);
                }
                s = curr.A.substring(0, curr.A.length() - 1) + " " + curr.B + " " + curr.C + temp;
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A.substring(0, curr.A.length() - 1), curr.B, curr.C + temp, curr.cnt + 1));
                    visit.add(s);
                }
            }
            if (curr.B.length() > 0) {
                char temp = curr.B.charAt(curr.B.length() - 1);
                String s = curr.A + temp + " " + curr.B.substring(0, curr.B.length() - 1) + " " + curr.C;
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A + temp, curr.B.substring(0, curr.B.length() - 1), curr.C, curr.cnt + 1));
                    visit.add(s);
                }
                s = curr.A + " " + curr.B.substring(0, curr.B.length() - 1) + " " + curr.C + temp;
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A, curr.B.substring(0, curr.B.length() - 1), curr.C + temp, curr.cnt + 1));
                    visit.add(s);
                }
            }
            if (curr.C.length() > 0) {
                char temp = curr.C.charAt(curr.C.length() - 1);
                String s = curr.A + temp + " " + curr.B + " " + curr.C.substring(0, curr.C.length() - 1);
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A + temp, curr.B, curr.C.substring(0, curr.C.length() - 1), curr.cnt + 1));
                    visit.add(s);
                }
                s = curr.A + " " + curr.B + temp + " " + curr.C.substring(0, curr.C.length() - 1);
                if (!visit.contains(s)) {
                    q.offer(new Info(curr.A, curr.B + temp, curr.C.substring(0, curr.C.length() - 1), curr.cnt + 1));
                    visit.add(s);
                }
            }
        }
        return -1;
    }

    private static boolean finish(Info curr) {
        if (curr.A.contains("B") || curr.A.contains("C") || curr.B.contains("A") || curr.B.contains("C")
                || curr.C.contains("A") || curr.C.contains("B")) {
            return false;
        }
        return true;
    }

    public static class Info {
        String A;
        String B;
        String C;
        int cnt;

        Info(String A, String B, String C, int cnt) {
            this.A = A;
            this.B = B;
            this.C = C;
            this.cnt = cnt;
        }

    }
}
