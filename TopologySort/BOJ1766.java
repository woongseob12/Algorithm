import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ1766 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        StringBuilder sb = new StringBuilder();

        int[] in = new int[N + 1];
        boolean[] visit = new boolean[N + 1];
        LinkedList<Integer>[] list = new LinkedList[N + 1];
        for (int i = 1; i <= N; i++) {
            list[i] = new LinkedList<>();
        }

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int A = Integer.parseInt(st.nextToken());
            int B = Integer.parseInt(st.nextToken());
            list[A].add(B);
            in[B]++;
        }

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 1; i <= N; i++) {
            if (in[i] == 0) {
                pq.offer(i);
            }
        }

        while (!pq.isEmpty()) {
            int curr = pq.poll();
            for (int i = 0; i < list[curr].size(); i++) {
                int next = list[curr].get(i);
                in[next]--;
                if (in[next] == 0) {
                    pq.offer(next);
                }
            }
            sb.append(curr + " ");
        }

        System.out.println(sb);
    }
}