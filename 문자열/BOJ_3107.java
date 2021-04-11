import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_3107 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String s = br.readLine();
		String[] addr = s.split(":");
		int zip = 8;
		for(int i = 0; i < addr.length; i++) {
			if(!addr[i].equals("")) {
				zip--;
			}
		}
		boolean flag = true;
		for(int i = 0 ; i <addr.length; i++) {
			if(flag && addr[i].equals("")) {
				flag = false;
				for(int j = 0; j < zip; j++) {
					sb.append("0000:");
				}
			} else if(!addr[i].equals("")) {
				sb.append(makeIdx(addr[i]));
			}
		}
		
		if(sb.length() != 40) {
			int loop = (40 - sb.length()) / 5;
			for(int i = 0 ; i <loop; i++) {
				sb.append("0000:");
			}
		}
		
		System.out.println(sb.substring(0,sb.length() - 1));
	}
	
	private static String makeIdx(String s) {
		StringBuilder e = new StringBuilder();
		int ori = 4 - s.length();
		for(int j = 0; j < ori; j++) {
			e.append(0);
		}
		e.append(s);
		e.append(":");
		return e.toString();
	}
}
