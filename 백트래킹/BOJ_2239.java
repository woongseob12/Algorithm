import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

public class BOJ_2239 {
	static final int size = 9;
	static int[][] arr;
	static boolean[][] row, col, square;
	static List<int[]> pos;

	private static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		arr = new int[size][size];
		row = new boolean[size][10];
		col = new boolean[size][10];
		square = new boolean[size][10];
		pos = new ArrayList<>();
		for (int i = 0; i < size; i++) {
			String s = br.readLine();
			for (int j = 0; j < size; j++) {
				arr[i][j] = s.charAt(j) - '0';
				if(arr[i][j] != 0) {
					// 행의 해당 숫자는 사용한 숫자
					row[i][arr[i][j]] = true;
					// 열의 해당 숫자는 사용한 숫자
					col[j][arr[i][j]] = true;
					// 작은 사각형의 해당 숫자는 사용한 숫자
					square[convert(i, j)][arr[i][j]] = true;
				} else {
					pos.add(new int[] {i,j});
				}
			}
		}
	}
	
	private static int convert(int y, int x) {
		/*
		 * 스도쿠의 작은 사각형은 아래 처럼 나눌 수 있음
		 * 해당 숫자를 작은 사각형을 구분해주는 인덱스라고 생각할 경우,
		 * 		0 1 2
		 *		3 4 5
		 *		6 7 8
		 * 행:  	(0 ~ 2) / 3 * 3 = 0
		 *  	(3 ~ 5) / 3 * 3	= 3
		 *  	(6 ~ 8) / 3 * 3	= 6
		 *  
		 * 열:  	(0 ~ 2) / 3 = 0
		 *  	(3 ~ 5) / 3 = 1
		 *  	(6 ~ 8) / 3 = 2
		 *  
		 * (행 / 3) * 3 + (열 / 3)의 계산으로 작은 사각형의 인덱스를 구할 수 있음
		 */
		return (y / 3) * 3 + x / 3;
	}
	
	private static void solve(int idx) {
		if(idx == pos.size()) {
			output();
			System.exit(0);
		}
		
		int r = pos.get(idx)[0];
		int c = pos.get(idx)[1];
		
		for(int num = 1; num <= 9; num++) {
			// 행, 열, 사각형의 조건을 모두 만족한다면 해당 숫자를 넣고 다음 단계 수행
			if(!row[r][num] && !col[c][num] && !square[convert(r, c)][num]) {
				arr[r][c] = num;
				row[r][num] = true;
				col[c][num] = true;
				square[convert(r, c)][num] = true;
				solve(idx + 1);
				arr[r][c] = 0;
				row[r][num] = false;
				col[c][num] = false;
				square[convert(r, c)][num] = false;
			}
		}
	}
	
	private static void output() {
		for(int i = 0; i < size; i++) {	
			for(int j = 0; j < size; j++) {
				System.out.print(arr[i][j]);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) throws IOException {	
		input();
		solve(0);
	}
}
