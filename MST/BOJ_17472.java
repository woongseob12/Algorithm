package ssafyAlgo_0326;

import java.io.*;
import java.util.*;

public class BOJ_17472 {
	static int N, M, cnt, ans;
	static final int INF = 987654321;
	static int[] dy = { 1, 0, -1, 0 };
	static int[] dx = { 0, 1, 0, -1 };
	static int[][] arr, adj;
	static ArrayList<int[]> pos[];
	static boolean[][] visit;

	public static void main(String[] args) throws IOException {
		input();
		solve();
	}

	private static void solve() {
		island();
		bridge();
	}

	private static void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		arr = new int[N][M];
		visit = new boolean[N][M];
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < M; j++) {
				arr[i][j] = Integer.parseInt(st.nextToken());
			}
		}
	}

	private static void island() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && arr[i][j] != 0) {
					visit[i][j] = true;
					cnt++;
					dfs(i, j);
				}
			}
		}
	}

	private static void dfs(int y, int x) {
		arr[y][x] = cnt;
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if(!visit[ny][nx] && arr[ny][nx] != 0) {
				visit[ny][nx] = true;
				dfs(ny, nx);
			}
		}
	}
	
	@SuppressWarnings("unchecked")
	private static void bridge() {
		adj = new int[cnt][cnt];
		pos = new ArrayList[cnt];
		for(int i = 0 ; i < cnt; i++) {
			pos[i] = new ArrayList<>();
		}
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(arr[i][j] != 0) {
					pos[arr[i][j] - 1].add(new int[] {i,j});
				}
			}
		}
		
		for(int i = 0; i < cnt; i++) {
			for(int j = i + 1; j < cnt; j++) {
				if(i == j) continue;
				int dist = INF;
				for(int k = 0; k < pos[i].size(); k++) {
					for(int l = 0; l < 4; l++) {
						int ny = pos[i].get(k)[0] + dy[l];
						int nx = pos[i].get(k)[1] + dx[l];
						int temp = 0;
						if(ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == i + 1) continue;
						while(ny >= 0 && ny < N && nx >= 0 && nx < M) {
							if(arr[ny][nx] == j + 1) {
								if(temp != 1) dist = Math.min(dist, temp);
								break;
							}
							if(arr[ny][nx] != 0) break;
							temp++;
							ny += dy[l];
							nx += dx[l];
						}
					}
				}
				adj[j][i] = adj[i][j] = dist;
			}
		}
		prim();
	}
	
	
	private static void prim() {
		boolean[] added = new boolean[cnt];
		int[] weight = new int[cnt];
		for(int i = 0; i < cnt; i++) {
			weight[i] = INF;
		}
		weight[0] = 0;
		
		int ret = 0;
		int vertex = 0;
		
		for(int i = 0; i < cnt; i++) {
			int cost = INF;
			for(int j = 0 ; j < cnt; j++) {
				if(!added[j] && cost > weight[j]) {
					cost = weight[j];
					vertex = j;
				}
			}
			if(cost == INF) {
				ret = -1;
				break;
			}
			ret += cost;
			added[vertex] = true;
			
			for(int j = 0 ; j < cnt; j++) {
				if(!added[j] && adj[vertex][j] != INF && weight[j] > adj[vertex][j]) {
					weight[j] = adj[vertex][j];
				}
			}
		}
		System.out.println(ret);
	}
}
