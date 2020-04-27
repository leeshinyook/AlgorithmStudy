#include <iostream>
#include <vector>
#include <algorithm>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;

int n;
int cnt = 0;
vector<int> col(50);
vector<int> diag1(50);
vector<int> diag2(50);
void search(int y) {
    if(y == n) {
        cnt++;
        return;
    }
    for(int x = 0; x < n; x++) {
        if(col[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
        search(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
    }
}
int main() {
    FASTSTD;
    FASTCIN;
    cin >> n;
    search(0);
    cout << cnt;
    return 0;
}