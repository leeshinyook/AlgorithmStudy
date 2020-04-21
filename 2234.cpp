#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int arr[51][51];
int N, M;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int visited[51][51];
int maxArea = INT_MIN;
int room = 0;
void BFS(int x, int y) {
    if(visited[x][y]) return;
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    int cnt = 0;
    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int mx = a + dx[i];
            int my = b + dy[i];
            if(visited[mx][my]) continue;
            if(mx < 0 || mx >= N || my < 0 || my >= M) continue;
            if(!(arr[x][y] & 1 << i)) continue;
            visited[mx][my] = true;
            q.push({mx, my});
            cnt++;
        }
    }
    room++;
    if(maxArea < cnt) {
        maxArea = cnt;
    }
}
void Break(int x, int y) {
    for(int i = 0; i < 4; i++) {
        if((arr[x][y] & (1 << i)) == 0) continue;
        memset(visited, false, sizeof(visited));
        arr[x][y] = arr[x][y] - (1 << i);
        BFS(x, y);
        arr[x][y] = arr[x][y] + (1 << i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            BFS(i, j);
        }
    }
    cout << room << '\n';
    cout << maxArea << '\n';
    maxArea = INT_MIN;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            Break(i, j);
        }
    };
    cout << maxArea;
    return 0;
}