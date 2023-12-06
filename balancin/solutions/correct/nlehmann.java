import java.util.*;
import java.io.*;

class balancin {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int c = in.nextInt();
        int g = in.nextInt();

        int min = Math.min(c, g);
        int max = Math.max(c, g);

        int gcd = 1;
        for (int i = 1; i <= 31623; ++i) {
            if (min % i == 0 && max % i == 0) {
                gcd = Math.max(gcd, i);
            }
            if (min % i == 0 && max % (min/i) == 0) {
                gcd = Math.max(gcd, min/i);
            }
        }

        if (min / gcd <= n && max / gcd <= n) {
            System.out.println("SI");
        } else {
            System.out.println("NO");
        }
    }
}


