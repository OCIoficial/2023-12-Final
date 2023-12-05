import java.util.*;
import java.io.*;

class balancin {
    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int c = in.nextInt();
        int g = in.nextInt();

        int gcd = 1;
        for (int i = 1; i <= Math.sqrt(Math.min(c, g)); ++i) {
            if (c % i == 0 && g % i == 0) {
                gcd = Math.max(gcd, i);
            }
        }

        if ((c / gcd <= n && g / gcd <= n) || Math.max(c, g) % Math.min(c, g) == 0) {
            System.out.println("SI");
        } else {
            System.out.println("NO");
        }
    }
}
