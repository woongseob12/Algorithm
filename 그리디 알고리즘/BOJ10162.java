import java.io.*;

public class BOJ10162 {
	
	static int[] microwave = {300, 60, 10};
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int time = Integer.parseInt(br.readLine());
		if(time % 10 != 0) {
			System.out.println("-1");
		} else {
			for(int i = 0; i < microwave.length; i++) {
				System.out.print(time / microwave[i] + " ");
				time %= microwave[i];
			}
		}
	}
}
