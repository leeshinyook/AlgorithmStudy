#include <iostream>
#include <vector>
using namespace std;

vector<int> permutation;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int arr[9][9];
int temp[9][9];
int N, M, MAX = 0;
int wallCnt = 0;
int E;
void getMax();
void DFS(int x, int y) {
    for(int i = 0; i < 4; i++) {
        int mx = x + dx[i];
        int my = y + dy[i];
        if(mx >= 1 && mx <= N && my >= 1 && my <= M) {
            if(arr[mx][my] == 0) {
                arr[mx][my] = 2;
                DFS(mx, my);
            }
        }
    }
}
void SetWall() {
    if(permutation.size() == 6) {
        wallCnt = 0;
        for(int i = 0; i < 6; i += 2) {
            if(arr[permutation[i]][permutation[i + 1]] == 0) {
                arr[permutation[i]][permutation[i + 1]] = 1;
                wallCnt++;
            }
        }
        if(wallCnt == 3) {
            for(int i = 1; i <= N; i++) {
                for(int j = 1; j <= M; j++) {
                    if(arr[i][j] == 2) {
                        DFS(i, j);
                    }
                }
            }
            getMax();
        }
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                arr[i][j] = temp[i][j];
            }
        }
    } else {
        for(int i = 1; i <= E; i++) {
            permutation.push_back(i);
            SetWall();
            permutation.pop_back();
        }
    }
}
void getMax() {
    int cnt = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] == 0) cnt++;
        }
    }
    if(MAX < cnt) MAX = cnt;
}
int main() {
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
            temp[i][j] = arr[i][j];
        }
    }
    if(N >= M) {
        E = N;
    } else {
        E = M;
    }
    SetWall();
    cout << MAX;
}