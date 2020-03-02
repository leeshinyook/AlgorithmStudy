#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

string A, B;
int AONE = 0, BONE = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> A >> B;
    for(int i = 0; i < A.length(); i++) {
        if(A[i] == '1') {
            AONE++;
        }
    }
    for(int i = 0; i < B.length(); i++) {
        if(B[i] == '1') {
            BONE++;
        }
    }
    if((AONE % 2 == 0 && AONE < BONE) || (AONE % 2 == 1 && AONE + 1 < BONE)) {
        cout << "DEFEAT";
    } else {
        cout << "VICTORY";
    }

}