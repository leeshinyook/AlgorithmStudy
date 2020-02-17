#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long dp[16][16];
int M, N, T;
int cnt = 0;
int X, Y, a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> T;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cnt++;
            if(cnt == T) {
                X = i;
                Y = j;
            } else if(T == 0) {
                X = N;
                Y = M;
                break;
            }
        }
    }
    for(int i = 1; i <= X; i++) {
        for(int j = 1; j <= Y; j++) {
            if(dp[i][j - 1] == 0 && dp[i - 1][j] == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    a = dp[X][Y];
    if(T == 0) {
        cout << a;
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    for(int i = X; i <= N; i++) {
        for(int j = Y; j <= M; j++) {
            if(dp[i][j - 1] == 0 && dp[i - 1][j] == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
    }
    b = dp[N][M];
    cout << a * b;

}