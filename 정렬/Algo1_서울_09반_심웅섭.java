import java.io.*;
import java.util.*;

public class Algo1_서울_09반_심웅섭 {
	static HashMap<Integer, String> alpha = new HashMap<>();
	static HashMap<String, Integer> num = new HashMap<>();

	public static void main(String[] args) throws IOException {
		// 입력 받기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		int M = Integer.parseInt(st.nextToken());
		int N = Integer.parseInt(st.nextToken());
		// 알파벳과 숫자가 연동되는 HashMap 두개 생성
		init();

		// M ~ N 까지의 알파벳 입력받기
		String[] s = new String[N - M + 1];
		for (int i = M; i <= N; i++) {
			String temp;
			// 두자리 일 경우
			if (i >= 10) {
				int first = i / 10;
				int second = i % 10;
				temp = alpha.get(first) + " " + alpha.get(second);
			} else {	// 한자리 일 경우
				temp = alpha.get(i);
			}
			s[i - M] = temp;
		}
		// 정렬해주기
		Arrays.sort(s);
		
		for (int i = 0; i <= N - M; i++) {
			// 한줄에 10개씩 출력
			if(i != 0 && i % 10 == 0) {
				sb.append("\n");
			}
			int ans;
			st = new StringTokenizer(s[i]);
			String str = st.nextToken();
			// 해당 알파벳의 숫자 찾기
			ans = num.get(str);
			// 두자리 일 경우
			if(st.hasMoreTokens()) {
				str = st.nextToken();
				ans *= 10;
				ans += num.get(str);
			}
			sb.append(ans + " ");
		}
		// 출력하기
		System.out.println(sb);
	}

	private static void init() {
		alpha.put(0, "zero");
		alpha.put(1, "one");
		alpha.put(2, "two");
		alpha.put(3, "three");
		alpha.put(4, "four");
		alpha.put(5, "five");
		alpha.put(6, "six");
		alpha.put(7, "seven");
		alpha.put(8, "eight");
		alpha.put(9, "nine");
		
		num.put("zero", 0);
		num.put("one", 1);
		num.put("two", 2);
		num.put("three", 3);
		num.put("four", 4);
		num.put("five", 5);
		num.put("six", 6);
		num.put("seven", 7);
		num.put("eight", 8);
		num.put("nine", 9);
	}
}
