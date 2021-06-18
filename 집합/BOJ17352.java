import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * BOJ17352
 */
public class BOJ17352 {
    static int[] parent;

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        parent = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < n - 2; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            union(a, b);
        }

        for (int i = 1; i <= n; i++) {
            if (getParent(i) != 1) {
                System.out.println(1 + " " + i);
                break;
            }
        }
    }

    private static void union(int a, int b) {
        a = getParent(a);
        b = getParent(b);
        if (a < b)
            parent[b] = a;
        else
            parent[a] = b;
    }

    private static int getParent(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = getParent(parent[x]);
    }
}