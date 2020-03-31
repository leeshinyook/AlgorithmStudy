#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int N;
int MIN = 987654321;
int routes[1000001];
vector<int> path;
bool visited[1000001];
void BFS() {
    queue<pair<int ,int>> q;
    q.push({N, 0});
    while(!q.empty()) {
        int x = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(x == 1) {
            int idx = x;
            while(idx != N) {
                path.push_back(idx);
                idx = routes[idx];
            }
            path.push_back(N);
            if(dist < MIN) {
                MIN = dist;
            }
            return;
        }
        if(x % 3 == 0 && !visited[x / 3]) {
            visited[x / 3] = true;
            q.push({x / 3 , dist + 1});
            routes[x / 3] = x;
        }
        if(x % 2 == 0 && !visited[x / 2]) {
            visited[x / 2] = true;
            q.push({x / 2, dist + 1});
            routes[x / 2] = x;
        }
        if(!visited[x - 1]) {
            visited[x - 1] = true;
            q.push({x - 1, dist + 1});
            routes[x - 1] = x;
        }


    }

}
int main() {
    cin >> N;
    BFS();
    cout << MIN << '\n';
    for(int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}
