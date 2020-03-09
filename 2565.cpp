#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

vector<pair<int , int>> v;
long long length[501];
int N;
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});

    }
    sort(v.begin(), v.end(), cmp);

    for(unsigned int i = 0; i < v.size(); i++) {
        length[i] = 1;
        for(unsigned int j = 0; j < i; j++) {
            if(v[i].second >= v[j].second) {
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }
    int ans = 0;
    for(unsigned int i = 0; i < v.size(); i++) {
        if(ans < length[i]) ans = length[i];
    }
    cout << N - ans;
}