#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int N, M;
int arr[100001];
// 최대공약수를 구하는 문제이다.
int Gcd(int a, int b) {
    if(b == 0) return a;
    else return Gcd(b, a % b);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] = abs(arr[i] - M);
    }
    int temp = arr[0];
    for(int i = 1; i < N; i++) {
        temp = Gcd(temp, arr[i]);
    }
    cout << temp;

}

