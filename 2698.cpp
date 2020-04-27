#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int N;
int n, k;
int dp[1001][1001][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    for(int i = 2; i <= 100; i++) {
        for(int j = 0; j <= i; j++) {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
        }
    }
    for(int i = 0; i < TC; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b][0] + dp[a][b][1] << '\n';
    }


};
