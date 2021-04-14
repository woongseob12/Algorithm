import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_14600 {
	static int k, x, y, n;
	static int[][] arr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		k = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		x = Integer.parseInt(st.nextToken());
		y = Integer.parseInt(st.nextToken());
		arr = new int[1<<k][1<<k];
		arr[y - 1][x - 1] = -1;
		sol(1 << k , 0, 0);
		for(int i = (1<<k) - 1 ; i >= 0; i--) {
			for(int j = 0; j < 1<<k; j++) {
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
	}
	
	public static void sol(int s, int y, int x) {
		n++;
		s /= 2;
		if (check(s, y, x)) arr[y + s - 1][x + s - 1] = n;
		if (check(s, y, x + s)) arr[y + s - 1][x + s] = n;
		if (check(s, y + s, x)) arr[y + s][x + s - 1] = n;
		if (check(s, y + s, x + s)) arr[y + s][x + s] = n;
		if(s == 1) {return;}
		sol(s , y, x);
		sol(s , y + s, x);
		sol(s , y, x + s);
		sol(s , y + s, x + s);
	}
	
	public static boolean check(int s, int y, int x) {
		for(int i = y ; i < y + s; i++) {
			for(int j = x; j < x + s; j++) {
				if(arr[i][j] != 0) {
					return false;
				}
			}
		}
		return true;
	}
}
