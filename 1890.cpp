#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int arr[101][101];
long long dp[101][101];

int T;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= T; j++) {
            cin >> arr[i][j];
        }
    }
    dp[1][1] = 1; // 경로의
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= T; j++) {
            if(i == T && j == T) continue;
            if(!dp[i][j]) continue;
            int num = arr[i][j];
            if((j + num) <= T) {
                dp[i][j + num] = dp[i][j + num] + dp[i][j];

            }
            if((i + num) <= T) {
                dp[i + num][j] = dp[i + num][j] + dp[i][j];
            }
        }
    }
    cout << dp[T][T];
}
