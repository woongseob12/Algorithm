import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class SW_5644 {
	static int M, A;
	static int[] p1, p2;
	static int[] dy = {0, -1, 0, 1, 0};
	static int[] dx = {0, 0, 1, 0, -1};
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int t = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= t; tc++) {
			// 입력
			StringTokenizer st = new StringTokenizer(br.readLine());
			M = Integer.parseInt(st.nextToken());
			A = Integer.parseInt(st.nextToken());
			p1 = new int[M + 1];
			p2 = new int[M + 1];
			st = new StringTokenizer(br.readLine());
			for(int i = 1 ; i <= M; i++) {
				p1[i] = Integer.parseInt(st.nextToken());
			}
			st = new StringTokenizer(br.readLine());
			for(int i = 1 ; i <= M; i++) {
				p2[i] = Integer.parseInt(st.nextToken());
			}
			BC[] bc = new BC[A];
			for(int i = 0; i < A; i++) {
				st = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(st.nextToken());
				int y = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());
				int p = Integer.parseInt(st.nextToken());
				bc[i] = new BC(y,x,c,p);
			}
			int[] pos1 = new int[2];
			int[] pos2 = new int[2];
			pos1[0] = pos1[1] = 1;
			pos2[0] = pos2[1] = 10;
			// 이동 횟수
			int total = 0;
			for(int i = 0 ; i <= M; i++) {
				pos1[0] += dy[p1[i]];
				pos1[1] += dx[p1[i]];
				pos2[0] += dy[p2[i]];
				pos2[1] += dx[p2[i]];
				
				int opt = 0;
				int sum = 0;
				for(int j = 0 ; j < A; j++) {
					int aTemp = 0;
					if(Math.abs(bc[j].y - pos1[0]) + Math.abs(bc[j].x - pos1[1]) <= bc[j].c) {
						aTemp = bc[j].p;
					}
					for(int k = 0; k < A; k++) {
						int bTemp = 0;
						if(Math.abs(bc[k].y - pos2[0]) + Math.abs(bc[k].x - pos2[1]) <= bc[k].c) {
							bTemp = bc[k].p;
						}
						// 다르면
						if(j != k) {
							sum = aTemp + bTemp;
						} else {
							sum = Math.max(aTemp, bTemp);
						}
						opt = Math.max(opt, sum);
					}
				}
				total += opt;
			}
			sb.append("#" + tc + " " + total + "\n");
		}
		System.out.println(sb);
	}

	
	static class BC{
		int y;
		int x;
		int c;
		int p;
		public BC(int y, int x, int c, int p) {
			super();
			this.y = y;
			this.x = x;
			this.c = c;
			this.p = p;
		}
	}
}

