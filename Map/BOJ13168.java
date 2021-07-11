import java.io.*;
import java.util.*;

public class BOJ13168 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int INF = 999999;
    static double[][] cost, discount;
    static Map<String, Integer> index = new HashMap<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        double ticketPrice = Double.parseDouble(st.nextToken());

        int idx = 0;
        st = new StringTokenizer(br.readLine());

        while (st.hasMoreTokens()) {
            String city = st.nextToken();
            index.put(city, idx++);
        }

        Double.parseDouble(br.readLine());
        String[] travelCity = br.readLine().split(" ");

        cost = new double[n][n];
        init(cost);
        discount = new double[n][n];
        init(discount);

        int trafficNum = Integer.parseInt(br.readLine());
        input(trafficNum);

        floyd(cost);
        floyd(discount);

        if (cal(travelCity, ticketPrice)) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    private static boolean cal(String[] travelCity, double ticketPrice) {
        double noNaeilro = 0, naeilro = 0;
        for (int i = 0; i < travelCity.length - 1; i++) {
            noNaeilro += cost[index.get(travelCity[i])][index.get(travelCity[i + 1])];
            naeilro += discount[index.get(travelCity[i])][index.get(travelCity[i + 1])];
        }
        if (noNaeilro > naeilro + ticketPrice) {
            return true;
        } else {
            return false;
        }
    }

    private static void input(int trafficNum) throws IOException {
        for (int i = 0; i < trafficNum; i++) {
            String[] temp = br.readLine().split(" ");
            cost[index.get(temp[1])][index.get(temp[2])] = Math.min(cost[index.get(temp[1])][index.get(temp[2])],
                    Double.parseDouble(temp[3]));
            cost[index.get(temp[2])][index.get(temp[1])] = Math.min(cost[index.get(temp[2])][index.get(temp[1])],
                    Double.parseDouble(temp[3]));
            if (temp[0].equals("Mugunghwa") || temp[0].equals("ITX-Saemaeul") || temp[0].equals("ITX-Cheongchun")) {
                discount[index.get(temp[1])][index.get(temp[2])] = discount[index.get(temp[2])][index.get(temp[1])] = 0;
            } else if (temp[0].equals("S-Train") || temp[0].equals("V-Train")) {
                discount[index.get(temp[1])][index.get(temp[2])] = Math
                        .min(discount[index.get(temp[1])][index.get(temp[2])], Double.parseDouble(temp[3]) / 2.0);
                discount[index.get(temp[2])][index.get(temp[1])] = Math
                        .min(discount[index.get(temp[2])][index.get(temp[1])], Double.parseDouble(temp[3]) / 2.0);
            } else {
                discount[index.get(temp[1])][index.get(temp[2])] = Math
                        .min(discount[index.get(temp[1])][index.get(temp[2])], Double.parseDouble(temp[3]));
                discount[index.get(temp[2])][index.get(temp[1])] = Math
                        .min(discount[index.get(temp[2])][index.get(temp[1])], Double.parseDouble(temp[3]));
            }
        }
    }

    private static void floyd(double[][] cost2) {
        int n = cost2.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (cost2[j][i] != INF && cost2[i][k] != INF && cost2[j][k] > cost2[j][i] + cost2[i][k]) {
                        cost2[j][k] = cost2[j][i] + cost2[i][k];
                    }
                }
            }
        }
    }

    private static void init(double[][] cost2) {
        for (double[] row : cost2) {
            Arrays.fill(row, INF);
        }
    }
}
