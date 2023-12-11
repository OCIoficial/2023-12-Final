import java.util.*;
import java.io.*;

class figuras {
    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] board = read_grid(in, n, m);
        int[][] mural = read_grid(in, n, m);

        int ones = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                ones += board[x][y];
            }
        }


        int intersection = 0;
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < m; ++y) {
                if (board[x][y] == 1 && mural[x][y] == 1) {
                    intersection += 1;
                }
            }
        }

        if (intersection > 0) {
            System.out.println(ones - intersection);
        } else {
            int d = bfs(board, mural);
            System.out.println(d + ones - 1);
        }
    }

    static int[][] read_grid(BufferedReader in, int n, int m) throws Exception {
        int[][] grid = new int[n][m];
        for (int x = 0; x < n; ++x) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int y = 0; y < m; ++y) {
                grid[x][y] = Integer.parseInt(st.nextToken());
            }
        }
        return grid;
    }

    static int bfs(int[][] board, int[][] mural) {
        int[] dx = {-1, 0, 1, 0};
        int[] dy = {0, -1, 0, 1};

        Queue<Tuple> q = new LinkedList<>();

        for (int x = 0; x < board.length; ++x) {
            for (int y = 0; y < board[0].length; ++y) {
                if (board[x][y] == 1) {
                    q.offer(new Tuple(x, y, 0));
                }
            }
        }

        while (!q.isEmpty()) {
            Tuple n = q.poll();
            if (mural[n.x()][n.y()] == 1) {
                return n.d();
            }

            for (int i = 0; i < 4; ++i) {
                int vx = n.x() + dx[i];
                int vy = n.y() + dy[i];
                if (vx < 0 || vx >= board.length || vy < 0 || vy >= board[0].length) {
                    continue;
                }

                if (board[vx][vy] == 0) {
                    q.offer(new Tuple(vx, vy, n.d() + 1));
                    board[vx][vy] = 1;
                }
            }
        }
        return 0;
    }
}

record Tuple(int x, int y, int d) {
    public int x() {
        return x;
    }

    public int y() {
        return y;
    }

    public int d() {
        return d;
    }
}
