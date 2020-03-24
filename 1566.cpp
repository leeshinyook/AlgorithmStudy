#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

int arr[20][20];
int temp[20][20];
int N, M;
bool AssertP() {
    int sum = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            sum += arr[i][j];
        }
        if(sum <= 0) return false;
        sum = 0;
    }
    for(int j = 1; j <= M; j++) {
        for(int i = 1; i <= N; i++) {
            sum += arr[i][j];
        }
        if(sum <= 0) return false;
        sum = 0;
    }
    return true;
}
void CurR(int x) { // 가로
    for(int i = 1; i <= M; i++) {
        arr[x][i] *= -1;
    }
}
void CurL(int x) { // 세로
    for(int i = 1; i <= N; i++) {
        arr[i][x] *= -1;
    }
}
void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}
vector<int> subset;
int K;
int ans = INT_MAX;
void search(int k) {
    if(k == K + 1) {
        for(int i = 0; i < subset.size(); i++) {
            if(subset[i] <= M) {
                CurL(subset[i]);
            } else {
                CurR(subset[i] - M);
            }
        }
        if(AssertP()) {
            if(ans > subset.size()) {
                ans = subset.size();
            }
        }
        init();
    } else {
        subset.push_back(k);
        search(k + 1);
        subset.pop_back();
        search(k + 1);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    K = N + M;
    search(1);
    if(ans != INT_MAX) {
        cout << ans;
    } else {
        cout << -1;
    }

}
