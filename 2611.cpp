#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> adj[1002];
int path[1002];
int dp[1002];
int N, M;
int DFS(int s) {
    if(s != 1 && !dp[s]) {
        for(auto n : adj[s]) {
            int w = DFS(n.first) + n.second;
            if(w > dp[s]) {
                dp[s] = w;
                path[s] = n.first;
            }
        }
    }
    return dp[s];
}
int main() {
    cin >> N;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    int temp, ans = 0;
    for(auto u : adj[1]) {
        int w = DFS(u.first) + u.second;
        if(w > ans) ans = w, temp = u.first;
    }
    cout << ans << '\n';
    cout << 1 << " ";
    for(int i = temp ; i; i = path[i]) {
        cout << i << " ";
    }


}

