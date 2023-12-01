import java.io.*;
import java.util.*;

class cachipun {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] puntaje = new int[n];
        while (k-- > 0) {
            int[] jugadas = new int[n];
            int[] cuenta = new int[3];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; ++i) {
                jugadas[i] = Integer.parseInt(st.nextToken());
                cuenta[jugadas[i]] += 1;
            }

            for (int i = 0; i < n; ++i) {
                int j = jugadas[i];
                puntaje[i] += cuenta[(j + 2) % 3] - cuenta[(j + 1) %3];
            }
        }

        for (int i = 0; i < n; ++i) {
            System.out.print(puntaje[i] + " ");
        }
        System.out.println();
    }
}
