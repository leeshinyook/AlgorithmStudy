//
// Created by 이신육 on 2020-02-05.
//
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#include <set>
#include <cstdlib>
#include <cstdio>
using namespace std;

long A, temp_A;
long B;
long Max = 0;
vector<int> num;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;
    temp_A = A;
    while(A) {
        int n = A % 10;
        num.push_back(n);
        A /= 10;
    }
    sort(num.begin(), num.end());
    do {
        double temp = 0;
        for(int i = 0; i < num.size(); i++) {
             temp += num[i] * pow(10, i);
             if(temp >= Max && temp <= B) {
                 Max = temp;
             }
        }
    } while(next_permutation(num.begin(), num.end()));
    int temp = Max;
    int len = 0;
    while(temp) {
        temp /= 10;
        len++;
    }
    if(len != num.size()) {
        cout << -1;
    } else {
        cout << Max;
    }

}
