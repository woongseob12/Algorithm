import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ2075 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
		PriorityQueue<Integer> minHeap = new PriorityQueue<>();
		for(int i = 0; i < n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < n; j++) {
				int val = Integer.parseInt(st.nextToken());
				if(maxHeap.size() >= n) {
					if(minHeap.peek() < val) {
						maxHeap.add(val);
						maxHeap.remove(minHeap.peek());
						minHeap.add(val);
						minHeap.remove();
					}
				}else {
					maxHeap.add(val);
					minHeap.add(val);
				}
			}
		}
		System.out.println(minHeap.peek());
	}
}
