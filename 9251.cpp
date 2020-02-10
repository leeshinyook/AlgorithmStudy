//
// Created by 이신육 on 2020-02-04.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;


int dp[1010][1010] = {0, };
char s1[1010], s2[1010];
int s1_len, s2_len;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    s1_len = strlen(s1);
    s2_len = strlen(s2);

    for(int i = 1; i <= s1_len; i++) {
        for(int j = 1; j <= s2_len; j++) {
            if(s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[s1_len][s2_len];
}
