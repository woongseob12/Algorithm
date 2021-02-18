package ssafy_algo_0218;

import java.io.*;
import java.util.*;

public class SW_1247 {
	static final int INF = 987654321;
	static int N, bit;
	static int[][] W;
	static int[][] dp;
	static ArrayList<Pos> info = new ArrayList<>();
	public static void main(String[] args) throws NumberFormatException, IOException {
		// 입력
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int tc = 1; tc <= T; tc++) {
			N = Integer.parseInt(br.readLine());
			info.clear();
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0 ; i < N + 2; i++) {
				info.add(new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
			}
			// 초기화
			memset();
			// TSP & 비트마스킹
			sb.append("#" + tc + " " + TSP(0, 0) + "\n");
		}
		System.out.println(sb);
	}
	
	static class Pos{
		int y;
		int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}	
	}
	
	static void memset() {
		dp = new int[N + 2][1 << (N + 2)];
		for(int i = 0; i < N + 2; i++) {
			for(int j = 0; j < (1 << (N + 2)); j++) {
				dp[i][j] = -1;
			}
		}
		W = new int[N + 2][N + 2];
		for(int i = 0 ; i < N + 2; i++) {
			for(int j = 0; j < N + 2; j++) {
				W[i][j] = Math.abs(info.get(i).y - info.get(j).y) + Math.abs(info.get(i).x - info.get(j).x);
			}
		}
	}
	
	static int TSP(int curr, int bit)
	{
	    if (bit == (1<<(N+2))-4) {
	    	return W[curr][1];
	    }
	    if (dp[curr][bit] != -1) {
	    	return dp[curr][bit];
	    }
	    
	    dp[curr][bit] = INF;
	    for (int i = 2; i < N + 2; i++)
	        if ((bit&(1 << i)) == 0) {
	        	int cost = TSP(i, bit | (1 << i)) + W[curr][i];
	        	dp[curr][bit] = Math.min(dp[curr][bit], cost);
	        }
	    return dp[curr][bit];
	}
}
