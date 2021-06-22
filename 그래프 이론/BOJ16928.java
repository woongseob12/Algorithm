import java.io.*;
import java.util.*;

public class BOJ16928 {
    static Map<Integer, Integer> m = new HashMap<>();
    static boolean[] visit = new boolean[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int loop = N + M;
        while (loop-- > 0) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            m.put(start, end);
        }
        System.out.println(bfs());
    }

    private static int bfs() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(1, 0));
        while (!q.isEmpty()) {
            Node curr = q.poll();
            if (curr.pos == 100) {
                return curr.cnt;
            }
            for (int i = 1; i <= 6; i++) {
                if (curr.pos + i < 101 && !visit[curr.pos + i]) {
                    visit[curr.pos] = true;
                    if (m.containsKey(curr.pos + i)) {
                        q.add(new Node(m.get(curr.pos + i), curr.cnt + 1));
                    } else {
                        q.add(new Node(curr.pos + i, curr.cnt + 1));
                    }
                }
            }
        }
        return -1;
    }

    static class Node {
        int pos;
        int cnt;

        Node(int pos, int cnt) {
            this.pos = pos;
            this.cnt = cnt;
        }
    }
}