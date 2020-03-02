#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
#include <utility>
#include <tuple>
#include <list>
#include <queue>

using namespace std;
const int MAX = 1005000;
vector<bool> primeNum(MAX); // 소수 - false, 소수아닌것 - true;
int N;
vector<int> Token;
bool cheker = true;
void erathos() {
    for(long i = 2; i <= MAX; i++) {
        if(primeNum[i]) continue; // 이미 체크된 배수는 확인하지 않는다.
        for(long j = i + i; j <= MAX; j += i) {
            primeNum[j] = true; // 소수가 아닌 것 체크
        }
    }
}
void tokenization(int num) {
    while(!Token.empty()) {
        Token.pop_back();
    } // 초기화
    int temp = num;
    while(temp) {
        Token.push_back(temp % 10);
        temp /= 10;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    erathos();
    cin >> N;

    for(int i = 2; i <= MAX; i++) {
        if(!primeNum[i]) {
            tokenization(i);
            int size = Token.size();
            cheker = true;
            for(int i = 0; i < size / 2; i++) {
                if(Token[i] != Token[size - i - 1]) {
                    cheker = false;
                }
            }
            if(cheker && N <= i) {
                cout << i;
                break;
            }
        }

    }
}
