package selfAlgo;

import java.util.Stack;

public class kakao2019_Crain {
	public static void main(String[] args) {
		Stack<Integer> s = new Stack<>();
		int[][] b = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
		int[] m = {1,5,3,5,1,2,1,4};
		int ans = solution(b, m);
		System.out.println(ans);
	}

	private static int solution(int[][] board, int[] moves) {
		int answer = 0;
		Stack<Integer> s = new Stack<>();
		int y = 0;
		int h = board.length;
		for(int i = 0 ; i < moves.length; i++) {
			y = 0;
			while(y < h && board[y][moves[i] - 1] == 0) {
				y++;
			}
			if(y != h) {
				if(!s.isEmpty() && s.peek() == board[y][moves[i] - 1]) {
					s.pop();
					answer += 2;
				}else {
					s.push(board[y][moves[i] - 1]);
				}
				board[y][moves[i] - 1] = 0;
			}
			System.out.println(s.peek());
		}
        return answer;
	}
}
