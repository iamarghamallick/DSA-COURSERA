import java.util.Scanner;
import java.util.Arrays;

public class ChangeDP {
    private static int getChange(int n, int a[], int dp[]) {
        // write your code here
        if (n == 0)
            return 0;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < a.length; i++) {
            if (n - a[i] >= 0) {
                int subAns = 0;
                if (dp[n - a[i]] != -1) {
                    subAns = dp[n - a[i]];
                } else {
                    subAns = getChange(n - a[i], a, dp);
                }
                if (subAns != Integer.MAX_VALUE && subAns + 1 < ans) {
                    ans = subAns + 1;
                }
            }
        }
        return dp[n] = ans;
    }

    public static void main(String[] args) {
        int a[] = { 1, 3, 4 };
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int dp[] = new int[n + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        System.out.println(getChange(n, a, dp));
        scanner.close();
    }
}
