import java.io.*;
import java.util.*;

public class BOJ12886 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if ((arr[0] + arr[1] + arr[2]) % 3 != 0) {
            System.out.println(0);
            return;
        }

        System.out.println(bfs(arr));

    }

    private static int bfs(int[] arr) {
        Queue<int[]> q = new LinkedList<>();
        Arrays.sort(arr);
        q.offer(arr);
        String tmp = arr[0] + " " + arr[1] + " " + arr[2];
        HashSet<String> visit = new HashSet<>();
        visit.add(tmp);
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            if (curr[0] == curr[1] && curr[1] == curr[2]) {
                return 1;
            }
            if (curr[0] != curr[1]) { // 1번 2번 교체
                int[] next = new int[3];
                next[0] = curr[0] + curr[0];
                next[1] = curr[1] - curr[0];
                next[2] = curr[2];

                if (next[1] > 0) {
                    Arrays.sort(next);
                    String key = next[0] + " " + next[1] + " " + next[2];
                    if (!visit.contains(key)) {
                        visit.add(key);
                        q.offer(next);
                    }
                }
            }

            if (curr[0] != curr[2]) { // 1번 3번 교체
                int[] next = new int[3];
                next[0] = curr[0] + curr[0];
                next[1] = curr[1];
                next[2] = curr[2] - curr[0];
                if (next[2] > 0) {
                    Arrays.sort(next);
                    String key = next[0] + " " + next[1] + " " + next[2];
                    if (!visit.contains(key)) {
                        visit.add(key);
                        q.offer(next);
                    }
                }
            }

            if (curr[1] != curr[2]) { // 2번 3번 교체
                int[] next = new int[3];
                next[0] = curr[0];
                next[1] = curr[1] + curr[1];
                next[2] = curr[2] - curr[1];

                if (next[2] > 0) {
                    Arrays.sort(next);
                    String key = next[0] + " " + next[1] + " " + next[2];
                    if (!visit.contains(key)) {
                        visit.add(key);
                        q.offer(next);
                    }
                }
            }

        }

        return 0;
    }
}
