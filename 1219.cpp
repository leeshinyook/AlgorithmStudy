#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 벨만-포드 알고리즘
// 다른 모든 노드로 가능 최단 경로를 구하는 알고리즘.

// 입력받은 출발점에서 도착점까지의 최단경로를 출력하십시요.
vector<pair<int, int>> adj[502];
long long dist[502];
int cost[502];
bool cycle = false;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int V, E , S , T; // V : 노드의 개수, E : 엣지의 개수, S: 시작점, T: 끝점
    int a, b, w; // (a, b) = w (가중치);

    cin >> V >> S >> T >> E;


    for(int i = 0; i < V + 1; i++) {
        dist[i] = LONG_LONG_MIN; // 거리도 무한대로 설정.
    }

    for(int j = 0; j < E; j++) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w * - 1});
    }
    for(int i = 0; i < V; i++ ) {
        cin >> cost[i];
    }

    dist[S] = cost[S]; // dist배열은 가중치가 저장된다.

    for(int i = 0; i < V + 100; i++) {
        for(int j = 0; j < V; j++) {
            for(auto &n : adj[j]) {
                if(dist[j] == LONG_LONG_MIN) continue;
                if(dist[j] == LONG_LONG_MAX) dist[n.first] = LONG_LONG_MAX;
                if(dist[n.first] < dist[j] + cost[n.first] + n.second) {
                    dist[n.first] = dist[j] + cost[n.first] + n.second;
                    if(i >= V - 1) dist[n.first] = LONG_LONG_MAX;
                }
            }
        }
    }
    if(dist[T] == LONG_LONG_MAX) {
        cout << "Gee";
    } else if(dist[T] == LONG_LONG_MIN){
        cout << "gg";
    } else {
        cout << dist[T];
    }


}