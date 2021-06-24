import java.io.*;
import java.util.*;

public class BOJ16499 {
    static Set<String> s = new HashSet<>();

    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            String word = br.readLine();
            String key = alpha(word);
            if (!s.contains(key)) {
                s.add(key);
            }
        }
        System.out.println(s.size());
    }

    private static String alpha(String word) {
        int[] arr = new int[26];
        for (int i = 0; i < word.length(); i++) {
            arr[word.charAt(i) - 'a']++;
        }
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) {
                sb.append(i + ": " + arr[i] + "/");
            }
        }
        return sb.toString();
    }
}