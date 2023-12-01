import java.io.*;
import java.util.*;

class dado {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        boolean[] arr= new boolean[n + 1];

        for (int i = 0; i < n / 2; ++i) {
            int v = sc.nextInt();
            if (arr[v]) {
                System.out.println("NO");
                return;
            }
            arr[v] = true;
            arr[n + 1 - v] = true;
        }
        System.out.println("SI");
    }
}
