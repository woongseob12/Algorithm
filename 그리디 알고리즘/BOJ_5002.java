import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
public class BOJ_5002 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int x = Integer.parseInt(br.readLine());
		String line = br.readLine();
		Stack<Character> s = new Stack<>();
		int m = 0, w = 0;
		for(int i = 0; i < line.length(); i++) {
			if(Math.abs(m - w) >= x) {
				if(m > w) {	// 남자가 더 많을 경우
					if(i == line.length() - 1 || (line.charAt(i) == 'M' && line.charAt(i + 1) == 'M')) {
						break;
					} else if (line.charAt(i) == 'M' && line.charAt(i + 1) == 'W') {
						line.replace(line.charAt(i),'W');
						line.replace(line.charAt(i + 1),'M');
					}
					
				} else {	// 여자가 더 많을 경우
					if(i == line.length() - 1 || (line.charAt(i) == 'W' && line.charAt(i + 1) == 'W')) {
						break;
					} else if (line.charAt(i) == 'W' && line.charAt(i + 1) == 'M') {
						line.replace(line.charAt(i),'M');
						line.replace(line.charAt(i + 1),'W');
					}
				}
			}
			s.push(line.charAt(i));
			// 인원 카운팅
			if(s.peek() == 'M') {
				m++;
			} else {
				w++;
			}
		}
		System.out.println(s.size());
	}
}
