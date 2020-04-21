#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int arr[1001][1001];
int dp[1001][1001];
int N, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = arr[1][1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            int temp1 = arr[i][j] + dp[i - 1][j];
            int temp2 = arr[i][j] + dp[i][j - 1];
            int temp3 = arr[i][j] + dp[i - 1][j - 1];
            int ans = max(temp1, max(temp2, temp3));
            dp[i][j] = ans;
        }
    }
    cout << dp[N][M];
}