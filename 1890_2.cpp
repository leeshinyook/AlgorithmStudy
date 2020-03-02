#include<iostream>
#include<vector>
#include<stdlib.h>
#include<cstring>
#include<stack>
#include<algorithm>

using namespace std;

int arr[101][101];
int dp[101][101];

int N, M, T;
int cnt = 0;
// 최대 나올수 있는 경로의 개수가 2^63 - 1이기 때문에 위 코드는 시간초과가 나올듯.
// 그냥 이런 풀이도 있다는 참고용
void search(int x, int y) {
    if(x < 1 || x > T || y < 1 || y > T) { // 장외
        return;
    }
    cout << x << " " << y << '\n';

    if(x == T && y == T) {
        cnt++;
        return;
    }
    int num = arr[x][y];
    // 오른쪽
    search(x, y + num);
    // 왼쪽
    search(x + num, y);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i = 1; i <= T; i++) {
        for(int j = 1; j <= T; j++) {
            cin >> arr[i][j];
        }
    }
    search(1, 1);
    cout << cnt;
}
