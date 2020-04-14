#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
using namespace std;

int arr[701][701];
int N, M;
int ans = INT_MIN;
int sum = 0;
bool visited[701][701];

vector<pair<int, int>> v[19] = {
        {{0,0}, {0,1}, {0,2}, {0,3}}
        ,{{0,0}, {1,0}, {2,0}, {3,0}}
        ,{{0,0}, {1,0}, {0,1}, {1,1}}
        ,{{0,0}, {0,1}, {0,2}, {1,2}}
        ,{{0,0}, {1,0}, {2,0}, {0,1}}
        ,{{0,0}, {1,0}, {1,1}, {1,2}}
        ,{{2,0}, {0,1}, {1,1}, {2,1}}
        ,{{1,0}, {1,1}, {1,2}, {0,2}}
        ,{{0,0}, {0,1}, {1,1}, {2,1}}
        ,{{0,0}, {1,0}, {0,1}, {0,2}}
        ,{{0,0}, {1,0}, {2,0}, {2,1}}
        ,{{0,0}, {1,0}, {2,0}, {1,1}}
        ,{{1,0}, {0,1}, {1,1}, {1,2}}
        ,{{0,1}, {1,0}, {1,1}, {2,1}}
        ,{{0,0}, {0,1}, {0,2}, {1,1}}
        ,{{0,0}, {0,1}, {1,1}, {1,2}}
        ,{{0,1}, {1,1}, {1,0}, {2,0}}
        ,{{1,0}, {1,1}, {0,1}, {0,2}}
        ,{{0,0}, {1,0}, {1,1}, {2,1}}

};
void BFS(int a, int b) {
    queue<pair<int, int>> q;
    q.push({a, b});
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 19; i++) {
            for(auto u : v[i]) {
                int dx = u.first + x;
                int dy = u.second + y;
                sum += arr[dx][dy];
            }
            if(ans < sum) {
                ans = sum;
            }
            sum = 0;
        }
    };
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            BFS(i, j);
        }
    }
    cout << ans;
}