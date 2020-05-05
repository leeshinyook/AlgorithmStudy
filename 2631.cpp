#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include "string"
using namespace std;

int N;
int arr[201];
int dp[201];
int ans = 0;
int main(){
    ios_base::sync_with_stdio(0);;
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++) {
        for(int j = i; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        if(ans < dp[i]) ans = dp[i];
    }
    cout << N - ans;
}
