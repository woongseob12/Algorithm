package Week3;

import java.io.*;
import java.util.*;

public class SW_1873 {
	static StringTokenizer stk = null;
	static int y, x, H, W;
	static char[][] map;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= T; tc++) {
			// 입력
			stk = new StringTokenizer(br.readLine(), " ");
			H = Integer.parseInt(stk.nextToken());
			W = Integer.parseInt(stk.nextToken());
			map = new char[H][W];
			for (int i = 0; i < H; i++) {
				String s = br.readLine();
				for (int j = 0; j < W; j++) {
					map[i][j] = s.charAt(j);
					if (map[i][j] == '^' || map[i][j] == 'v' || map[i][j] == '<' || map[i][j] == '>') {
						y = i;
						x = j;
					}
				}
			}
			// 풀이
			br.readLine();
			String op = br.readLine();
			for (int i = 0; i < op.length(); i++) {
				command(op.charAt(i));
			}
			// 출력
			sb.append("#" + tc + " ");
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					sb.append(map[i][j]);
				}
				sb.append('\n');
			}
		}
		System.out.println(sb);
	}

	private static void command(char c) {
		if (c == 'U') {
			if (y - 1 >= 0 && map[y - 1][x] == '.') {
				map[y][x] = '.';
				y--;
			}
			map[y][x] = '^';
		} else if (c == 'D') {
			if (y + 1 < H && map[y + 1][x] == '.') {
				map[y][x] = '.';
				y++;
			}
			map[y][x] = 'v';
		} else if (c == 'L') {
			if (x - 1 >= 0 && map[y][x - 1] == '.') {
				map[y][x] = '.';
				x--;
			}
			map[y][x] = '<';
		} else if (c == 'R') {
			if (x + 1 < W && map[y][x + 1] == '.') {
				map[y][x] = '.';
				x++;
			}
			map[y][x] = '>';
		} else {
			if (map[y][x] == '^') {
				int pos = y;
				while (--pos >= 0) {
					if (map[pos][x] == '*') {
						map[pos][x] = '.';
						break;
					}
					if (map[pos][x] == '#') {
						break;
					}
				}
			} else if (map[y][x] == 'v') {
				int pos = y;
				while (++pos < H) {
					if (map[pos][x] == '*') {
						map[pos][x] = '.';
						break;
					}
					if (map[pos][x] == '#') {
						break;
					}
				}
			} else if (map[y][x] == '<') {
				int pos = x;
				while (--pos >= 0) {
					if (map[y][pos] == '*') {
						map[y][pos] = '.';
						break;
					}
					if (map[y][pos] == '#') {
						break;
					}
				}
			} else if (map[y][x] == '>') {
				int pos = x;
				while (++pos < W) {
					if (map[y][pos] == '*') {
						map[y][pos] = '.';
						break;
					}
					if (map[y][pos] == '#') {
						break;
					}
				}
			}
		}
	}
}
