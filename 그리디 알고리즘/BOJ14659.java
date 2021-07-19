import java.io.*;
import java.util.*;

public class BOJ14659 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::valueOf).toArray();

		int ans = 0;
		for(int i = 0 ; i < n; i++) {
			int temp = 0;
			for(int j = i + 1; j < n; j++) {
				if(arr[i] > arr[j]) {
					temp++;
				} else {
					break;
				}
			}
			ans = Math.max(ans,  temp);
		}
		System.out.println(ans);
	}
}
