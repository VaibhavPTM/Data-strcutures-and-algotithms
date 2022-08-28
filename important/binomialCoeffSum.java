import java.math.BigInteger;
import java.util.Scanner;
/**
 * binomialCoeffSum
 */
public class binomialCoeffSum {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextInt();
        System.out.println(binomialCoeffSum1(n));
        in.close();
    }
    public static BigInteger binomialCoeffSum1(long n)
    {
        BigInteger [][] C = new BigInteger[(int) (n+1)][(int) (n+1)];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= Math.min(i, n); j++) {
                if (j == 0 || j == i)
                    C[i][j] = BigInteger.valueOf(1);
                else
                    C[i][j] = C[i - 1][j - 1].add(C[i - 1][j]);
            }
        }

        // Calculating the sum.
        BigInteger sum = new BigInteger("0");
        for (int i = 0; i <= n; i++)
            sum = sum.add((C[(int) n][i]));

        return sum;
    }
}