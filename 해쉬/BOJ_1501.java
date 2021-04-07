import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.StringTokenizer;

// 19:40 ~ 20:22
public class BOJ_1501 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		// 1. 맵 만들어서 사전 만들기
		int N = Integer.parseInt(br.readLine());
		HashMap<String, Integer> dic = new HashMap<>();
		for (int i = 0; i < N; i++) {
			String key = br.readLine();
			dic.put(key, 1);
		}
		// 2. 문장이 들어오면 단어로 분리해서 저장하기
		int M = Integer.parseInt(br.readLine());
		for (int i = 0; i < M; i++) {
			List<String> word = new ArrayList<>();
			StringTokenizer st = new StringTokenizer(br.readLine());
			while (st.hasMoreTokens()) {
				word.add(st.nextToken());
			}
			// 3. 단어별로 비교
			int ans = 1;
			for (int j = 0; j < word.size(); j++) {
				int temp = 0;
				// 3-1. 섞은 문자
				String curr = word.get(j);
				char startWord = curr.charAt(0);
				char endWord = curr.charAt(curr.length() - 1);
				
				// 3-2. 맵 순회
				for (String mKey : dic.keySet()) {
					if (mKey.charAt(0) != startWord || mKey.length() != curr.length() || mKey.charAt(mKey.length() - 1) != endWord) continue;
					int[] alpha = new int[26 * 2];
					// 현재 단어 넣어주기
					for (int k = 1; k < curr.length() - 1; k++) {
						if (curr.charAt(k) >= 'a' && curr.charAt(k) <= 'z') {
							alpha[curr.charAt(k) - 'a']++;
						} else {
							alpha[curr.charAt(k) - 'A' + 26]++;
						}
					}
					// 맵 단어 넣어주기
					for(int k = 1; k < mKey.length() - 1; k++) {
						if (mKey.charAt(k) >= 'a' && mKey.charAt(k) <= 'z') {
							alpha[mKey.charAt(k) - 'a']--;
						} else {
							alpha[mKey.charAt(k) - 'A' + 26]--;
						}
					}
					boolean flag = true;
					for (int idx = 0; idx < 26 * 2; idx++) {
						if(alpha[idx] != 0) {
							flag = false;
							break;
						}
					}
					if(flag) {
						temp++;
					}
				}
				ans *= temp;
			}
			sb.append(ans + "\n");
		}
		// 4. 출력
		System.out.println(sb);
	}
}
