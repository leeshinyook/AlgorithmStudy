import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static int m, n, count;
    static int[][] map;
    static int[] dx = { 0, 0, 1, -1 };
    static int[] dy = { 1, -1, 0, 0 };

    public static void main(String[] args) {

        int k;
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> ar = new ArrayList<Integer>();

        m = sc.nextInt();
        n = sc.nextInt();
        k = sc.nextInt();

        map = new int[m][n];

        for(int i=0; i<k; i++) {
            int sx = sc.nextInt();
            int sy = sc.nextInt();
            int ex = sc.nextInt();
            int ey = sc.nextInt();

            for(int j=sy; j<ey; j++) {
                for(int l=sx; l<ex; l++) {
                    map[j][l] = 1;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(map[i][j]==0) {
                    count = 0;
                    dfs(i, j);
                    ar.add(count);
                }
            }
        }

        Collections.sort(ar);
        System.out.println(ar.size());

        for(int i=0; i<ar.size(); i++) {
            System.out.print(ar.get(i) + " ");
        }

    }

    static public void dfs (int y, int x) {
        map[y][x] = 1;
        count++;

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny<0 || nx<0 || ny>=m || nx>=n) continue;
            if(map[ny][nx]==1) continue;

            dfs(ny, nx);
        }
    }
}