import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int[][] mat;
    static int[][] check;
    static int T, len = 0;
    static int[] house = new int[1000];
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {-1, 1, 0, 0};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        sc.nextLine();
        mat = new int[T + 1][T + 1];
        check = new int[T + 1][T + 1];
        int count = 0;
        for (int i = 0; i < T; i++) {
            String[] num = sc.nextLine().split("");
            for(int j = 0; j < T; j++) {
                mat[i][j] = Integer.parseInt(num[j]);
            }
        }
        for (int i = 0; i < T; i++) {
            for (int j = 0; j < T; j++) {
                if (mat[i][j] == 1 && check[i][j] == 0) {
                    DFS(i, j, ++count);
                }
            }
        }
        for(int i = 1; i < house.length; i++) {
            if(house[i] == 0) break;
            len++;
        }
        Arrays.sort(house, 0, len + 1);
        System.out.println(count);
        for(int i = 1; i <= len; i++) {
            System.out.println(house[i]);
        }
    }
    private static void DFS(int x, int y, int count) {
        check[x][y] = count;
        house[count]++;
        for (int i = 0; i < dx.length; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < T && 0 <= ny && ny < T) {
                if (mat[nx][ny] == 1 && check[nx][ny] == 0)
                    DFS(nx, ny, count);
            }
        }
    }
}