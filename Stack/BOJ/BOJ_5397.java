import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class BOJ_5397 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int t = 1; t <= T; t++) {
			Stack<Character> front = new Stack<>();
			Stack<Character> back = new Stack<>();
			String s = br.readLine();

			for(int i = 0; i < s.length(); i++) {
				if(s.charAt(i) == '<') {
					if(!front.isEmpty()) {
						back.add(front.pop());
					}
				} else if(s.charAt(i) == '>') {
					if(!back.isEmpty()) {
						front.add(back.pop());
					}
				} else if(s.charAt(i) == '-') {
					if(!front.isEmpty()) {
						front.pop();
					}
				} else {
					front.add(s.charAt(i));
				}
			}
			
			while(!front.isEmpty()) {
				back.add(front.pop());
			}
			while(!back.isEmpty()) {
				sb.append(back.pop());
			}
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
