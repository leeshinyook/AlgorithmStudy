#include <iostream>
#include <vector>
using namespace std;


int M, N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    vector<int> deposit(2 * M - 1, 1);
    while(N--) {
        int zero, one, two;
        cin >> zero >> one >> two;
        for(int i = zero; i < zero + one; i++) {
            deposit[i]++;
        }
        for(int i = zero + one; i < 2 * M - 1; i++){
            deposit[i]+= 2;
        }
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            if(j == 0) cout << deposit[M - i - 1] << " ";
            else {
                cout << deposit[M + j - 1] << " ";
            }
        }
        cout << '\n';
    }
}