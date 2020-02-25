#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>

#define FASTSTD ios::sync_with_stdio(0)
#define FASTCIN cin.tie(0)
using namespace std;
vector<int> primeNum(10000);
int visited[10000];
int T;
int A, B; // 두 소수
int dist;
queue<pair<int, int>> q;
int BFS(int s) {
    q.push({s, 0});
    visited[s] = true;

    while(!q.empty()) {
        int v = q.front().first;
        dist = q.front().second;
        int temp = v;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int a = temp % 10;
            for(int j = 0; j < 10; j++) {
                int num = v - (a * pow(10, i)) + (j * (pow(10, i)));
                if(num < 1000 || num > 9999) continue;
                if(num == B && primeNum[num]) {
                    return 1;
                }
                if(primeNum[num] && !visited[num]) {
                    visited[num] = true;
                    q.push({num, dist + 1});
                }
            }
            temp /= 10;
        }
    }
    return -1;
}
void init() {
    memset(visited, false, sizeof(visited));
    while(!q.empty()) {
        q.pop();
    }
}
int main() {
    FASTSTD;
    FASTCIN;
    for(int i = 2; i <= 10000; i ++) {
        primeNum[i] = i;
    }
    for(int i = 2; i <= 10000; i++) {
        if(primeNum[i] == 0) continue;
        for(int j = i + i; j <= 10000; j += i) {
            primeNum[j] = 0;
        }
    }

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> A >> B;
        int result = BFS(A);
        if(result == -1) {
            cout << "Impossible" << '\n';
        } else {
            if(dist) {
                cout << dist + 1 << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        init();

    }


}