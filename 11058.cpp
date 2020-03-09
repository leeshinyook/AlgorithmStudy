#include <iostream>
#include <vector>
using namespace std;

long long dp[101];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 4;
    dp[5] = 5;
    dp[6] = 6;
    for(int i = 7; i <= 100; i++) {
        for(int j = 1; j < i; j++) {
            dp[i] = max(dp[i], max(dp[j] + (dp[j] * (i - 2 - j)), dp[i - 1] + 1));
        }
    }
    int N;
    cin >> N;
    cout << dp[N];
}
