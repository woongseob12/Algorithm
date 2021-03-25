package ssafyAlgo_0325;

import java.io.*;
import java.util.*;

public class SWEA_3307 {
	static ArrayList<Integer> ans;
	static int[] arr;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for(int t = 1; t<= T; t++) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr= new int[N];
			for(int i = 0 ; i < N; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			ans = new ArrayList<>();
			ans.add(arr[0]);
			
			for (int i = 1; i < N; i++) {
				if (ans.get(ans.size() - 1) < arr[i]) {
					ans.add(arr[i]);
				}
				else {
					int idx = lower_bound(arr[i]);
					ans.set(idx, arr[i]);
				}
			}
			sb.append("#"+t+" " + ans.size()+"\n");
		}
		System.out.println(sb);
	}
	
	private static int lower_bound(int target) {
	    int begin = 0;
	    int end = ans.size();
	    
	    while(begin < end) {
	    	int mid = (begin + end) / 2;
	        
	        if(ans.get(mid) >= target) {
	        	end = mid;
	        }
	        else {
	        	begin = mid + 1;
	        }
	    }
	    return end;
	}
}
