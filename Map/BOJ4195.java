import java.io.*;
import java.util.*;

public class BOJ4195 {
    static int[] parent, network;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int TC = Integer.parseInt(br.readLine());
        for (int tc = 0; tc < TC; tc++) {
            int n = Integer.parseInt(br.readLine());
            parent = new int[2 * n];
            network = new int[2 * n];
            Arrays.fill(network, 1);
            for (int i = 0; i < 2 * n; i++) {
                parent[i] = i;
            }

            HashMap<String, Integer> nameToIdx = new HashMap<>();
            int idx = 0;
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                String a = st.nextToken();
                String b = st.nextToken();
                if (!nameToIdx.containsKey(a)) {
                    nameToIdx.put(a, idx++);
                }
                if (!nameToIdx.containsKey(b)) {
                    nameToIdx.put(b, idx++);
                }
                int aIdx = nameToIdx.get(a);
                int bIdx = nameToIdx.get(b);
                System.out.println(unionParent(aIdx, bIdx));
            }
        }

    }

    private static int unionParent(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a == b) {
            return network[a];
        } else {
            if (a < b) {
                parent[b] = a;
                network[a] += network[b];
                return network[a];
            } else {
                parent[a] = b;
                network[b] += network[a];
                return network[b];
            }
        }
    }

    private static int getParent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = getParent(parent[x]);
    }
}
