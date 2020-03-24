#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> odd;
vector<int> even;
int N, H;
int total = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> H;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if(i % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    int ans = INT_MAX;
    for(int i = 1; i <= H; i++) {
        auto cnt = even.size() - (lower_bound(even.begin(), even.end(), i) - even.begin());
        cnt += odd.size() - (upper_bound(odd.begin(), odd.end(), H - i) - odd.begin());

        if(ans == cnt) {
            total++;
        } else if(ans > cnt) {
            ans = cnt;
            total = 1;
        }
    }
    cout << ans << " " << total;
}