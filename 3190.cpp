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

const int MAX = 101;
const int SNAKE = 1, APPLE = 2;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};
int N,K,I, map[MAX][MAX];
vector<pair<int,char>> command;
list <pair<int, int>> snake;

int simul() {
    int x =1, y = 1, dir = 2, com_idx = 0;
    int time = 0;
    snake.push_back(make_pair(1, 1));
    map[1][1] = SNAKE;
    while(true) {
        time++; // 시간올려
        x += dx[dir]; // 위치 조정
        y += dy[dir];
        // 벽과 몸통에 부딪히는가?
    if(x < 1 || x > N || y < 1 || y > N || map[x][y] == SNAKE) {
            break;
        }
        // 사과가 아니면 꼬리 제거
        if(map[x][y] == 0) {
            map[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }
        // 머리 진행한다
        snake.push_front(make_pair(x, y));
        map[x][y] = SNAKE;
        if (com_idx < I && command[com_idx].first == time) {
            if (command[com_idx].second == 'L') dir += 1, dir %= 4;
            else dir += 3, dir %= 4;
            com_idx++;
        }
    }
    return time;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = APPLE;
    }
    cin >> I;
    for(int i = 0; i < I; i++) {
        int t;
        char dir;
        cin >> t >> dir;
        command.push_back(make_pair(t, dir));
    }
    cout << simul();
}
