#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

priority_queue<int, vector<int>, greater<>> pos_q;
priority_queue<int, vector<int>, greater<>> nega_q;
int T;
int num;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < T; j++) {
            cin >> num;
            if(num >= 0) {
                pos_q.push(num);
            } else {
                nega_q.push(num);
            }
            int total_size = pos_q.size() + nega_q.size();
            if(total_size > T) {
                if(nega_q.size()) {
                    nega_q.pop();
                } else {
                    pos_q.pop();
                }
            }
        }
    }
    int ans;
    if(nega_q.size()) {
        ans = nega_q.top();
    } else {
        ans = pos_q.top();
    }

    cout << ans;
}