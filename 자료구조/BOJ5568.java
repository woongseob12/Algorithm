import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class BOJ5568 {
    static int n, k;
    static int[] seq;
    static boolean[] visit;
    static String[] arr;
    static Set<String> ans = new HashSet<>();

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        k = Integer.parseInt(br.readLine());
        arr = new String[n];
        seq = new int[n];
        visit = new boolean[n];
        for (int i = 0; i < n; i++) {
            arr[i] = br.readLine();
        }

        dfs(0);
        System.out.println(ans.size());
    }

    private static void dfs(int cnt) {
        if (cnt == k) {
            makeNum();
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                visit[i] = true;
                seq[cnt] = i;
                dfs(cnt + 1);
                visit[i] = false;
            }
        }
    }

    private static void makeNum() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k; i++) {
            sb.append(arr[seq[i]]);
        }
        ans.add(sb.toString());
    }
}
