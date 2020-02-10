//
// Created by 이신육 on 2020-02-03.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[101][100001];
int arr[101][2];
int T, M;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> T;
    for(int i = 1; i <= M; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for(int i = 1; i <= M; i++) {
        for(int j = 0; j <= T; j++) {
            dp[i][j] = dp[i - 1][j];
            if(j - arr[i][0] >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
            }
        }
    }
    cout << dp[M][T];
}