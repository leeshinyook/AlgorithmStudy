#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];
int N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[1] = 0;
    for(int i = 1; i <= N; i++) {
        int ma = INT_MIN, mi = INT_MAX;
        for(int j = i; j > 0; j--) {
            ma = max(ma, arr[j]);
            mi = min(mi, arr[j]);
            dp[i] = max(dp[i], ma - mi + dp[j - 1]);
        }
    }
    cout << dp[N];




}