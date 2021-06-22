import java.io.*;
import java.util.*;

public class BOJ1972 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        StringBuilder sb = new StringBuilder();
        while (!s.equals("*")) {
            if (isSurprising(s)) {
                sb.append(s + " is surprising.\n");
            } else {
                sb.append(s + " is NOT surprising.\n");
            }
            s = br.readLine();
        }
        System.out.println(sb);
    }

    private static boolean isSurprising(String s) {
        int len = s.length();
        for (int i = 1; i <= len - 1; i++) {
            Set<String> D = new HashSet<>();
            for (int j = 0; j + i < len; j++) {
                StringBuilder tmp = new StringBuilder();
                tmp.append(s.charAt(j)).append(s.charAt(j + i));
                if (D.contains(tmp.toString())) {
                    return false;
                } else {
                    D.add(tmp.toString());
                }
            }
        }
        return true;
    }
}
