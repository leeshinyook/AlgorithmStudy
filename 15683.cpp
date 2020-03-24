#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int CCTV_cnt = 0;
int arr[10][10];
int temp[10][10];
vector<pair<int, int>> cctv;
vector<int> permutation;
int ans = INT_MAX;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
void check(int x, int y, int angle) {
    int nx = x;
    int ny = y;
    while(true) {
        nx += dx[angle];
        ny += dy[angle];
        if(arr[nx][ny] == 6) break;
        if(arr[nx][ny] != 0) continue;
        if(nx < 1 || nx > N || ny < 1 || ny > M) break;
        arr[nx][ny] = 9; // 감시 = 9
    }
}
void DFS(int x, int y, int order) {
    int num = arr[x][y];
    if(num == 1) {
        check(x, y, order % 4);
    }
    if(num == 2) {
        check(x, y, order % 4);
        check(x, y, (order + 2) % 4);
    }
    if(num == 3) {
        check(x, y, order % 4);
        check(x, y, (order + 3) % 4);
    }
    if(num == 4) {
        check(x, y, order % 4);
        check(x, y, (order + 1) % 4);
        check(x, y, (order + 2) % 4);
    }
    if(num == 5) {
        for(int i = 0; i < 4; i++) {
            check(x, y, i % 4);
        }
    }
}
void findMaxSafetyArea() {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] == 0) cnt++;
        }
    }
    if(ans > cnt) ans = cnt;
}
void copyArr() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}
void search() {
    if(permutation.size() == CCTV_cnt) {
        for(int i = 0; i < CCTV_cnt; i++) {
            DFS(cctv[i].first, cctv[i].second, permutation[i]);
        }
        findMaxSafetyArea();
        copyArr();
    } else {
        for(int i = 0; i < 4; i++) {
            permutation.push_back(i);
            search();
            permutation.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            if(arr[i][j] != 6 && arr[i][j] != 0) {
                cctv.push_back({i, j});
                CCTV_cnt++;
            }
            temp[i][j] = arr[i][j];
        }
    }
    search();
    cout << ans;
}