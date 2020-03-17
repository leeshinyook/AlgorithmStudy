#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int cnt = 0;
int add[2] = {4, 7};
queue<long long> q;
void search(long long num) {
    q.push(num);
    while(!q.empty()) {
        long long x = q.front();
        q.pop();
        x *= 10;
        if(x > 1000000000) break;
        for(int i = 0; i < 2; i++) {
            x += add[i];
            if(x > M) continue;
            if(x >= N && x <= M) cnt++;
            q.push(x);
            x -= add[i];
        }
    }

}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    search(0);
    cout << cnt;

}
