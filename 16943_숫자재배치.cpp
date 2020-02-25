#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main(void) {
    string num1;
    int num2;
    cin>>num1>>num2;
    vector<int> v1(num1.size());
    for (int i=0;i<num1.size();i++) {
        v1[i]=num1[i]-'0';
    }
    sort(v1.begin(), v1.end());
    int result = -1;

    do {
        if (v1[0] == 0)
            continue;
        int number = 0;
        for (int i=0;i<v1.size();i++) {
            number = number*10 + v1[i];
        }
        if (number <= num2) {
            result = number;
        }
        else {
            break;
        }
    } while (next_permutation(v1.begin(), v1.end()));
    cout<<result;
    return 0;
}

