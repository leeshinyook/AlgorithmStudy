#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include "string"
using namespace std;

int N, temp, ans = 0;
vector<int> arr;
void Search() {
    if(arr.size() == 2) {
        if(ans < temp) ans = temp;
        return;
    } else {
        for(int i = 1; i < arr.size() - 1; i++) {
            int chose = arr[i];
            temp += arr[i - 1] * arr[i + 1];
            arr.erase(arr.begin() + i);
            Search();
            arr.insert(arr.begin() + i, chose);
            temp -= arr[i - 1] * arr[i + 1];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);;
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    Search();
    cout << ans;
}
