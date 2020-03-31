#include <iostream>
#include <vector>
#include <map>

using namespace std;
vector<int> gap;
int N;
int sum = 0;
void init() {
    while(!gap.empty()) gap.pop_back();
    sum = 0;
}
int main() {
    cin >> N;
    while(N--) {
        init();
        string str;
        cin >> str;
        for(int i = 0; i < str.length(); i++) {
            if(str[i] - 65 <= 13) {
                gap.push_back(str[i] - 65);
            } else {
                gap.push_back(91 - str[i]);
            }
        }
        int len = gap.size();
        int move = len - 1;
        for(int i = 0; i < gap.size(); i++) {
            sum += gap[i];
            int pivot = i + 1;
            while(pivot < gap.size() && gap[pivot] == 0) {
                pivot++;
            }
            int next_move = (i + len - pivot) + min(i, (len - pivot));
            move = min(move, next_move);
        }
        cout << move + sum << '\n';
    }



}