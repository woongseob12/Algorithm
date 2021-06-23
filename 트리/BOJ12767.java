import java.io.*;
import java.util.*;

public class BOJ12767 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        Set<BitSet> tree = new HashSet<>();
        while (n-- > 0) {
            int[] arr = new int[1 << m + 1];
            BitSet b = new BitSet(1 << m + 1);
            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                int val = Integer.parseInt(st.nextToken());
                int idx = 1;
                while (arr[idx] != 0) {
                    if (arr[idx] > val) {
                        idx = idx * 2;
                    } else {
                        idx = idx * 2 + 1;
                    }
                }
                arr[idx] = val;
                b.set(idx);
            }
            tree.add(b);
        }
        System.out.println(tree.size());
    }

}
