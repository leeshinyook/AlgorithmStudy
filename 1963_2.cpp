#include <iostream>
#include <queue>
#include <cmath>
#include <cstring> //memset
using namespace std;

const int MAX = 10000;

int start, destination;
int minFactor[MAX];
int cache[MAX];

//에라토스테네스의 체
void eratosthenes(void) {
    minFactor[0] = minFactor[1] = -1;
    for (int i = 2; i < MAX; i++)
        minFactor[i] = i;
    for (int i = 2; i * i < MAX; i++)
        if (minFactor[i] == i)
            for (int j = i * i; j < MAX; j += i)
                if (minFactor[j] == j)
                    minFactor[j] = i;
}

int BFS(void) {
    memset(cache, 0, sizeof(cache));
    queue<int> q;
    q.push(start);
    cache[start] = 1;
    while (!q.empty()) {
        int curNum = q.front();
        q.pop();
        if (curNum == destination)
            return cache[curNum] - 1;

        int digit[4] = { curNum / 1000, (curNum / 100) % 10, (curNum / 10) % 10, curNum % 10 };
        for (int i = 0; i < 4; i++) {
            if (i == 0) {
                for (int j = 1; j < 10; j++) {
                    int changeNum=0;
                    for (int k = 0; k < 4; k++)
                        if (i != k)
                            changeNum += digit[k] * pow(10, 3 - k);
                        else
                            changeNum += j * pow(10, 3 - k);
                    if (minFactor[changeNum] == changeNum && cache[changeNum] == 0) {
                        cache[changeNum] = cache[curNum] + 1;
                        q.push(changeNum);
                    }
                }
            }
            else {
                for (int j = 0; j < 10; j++)
                {
                    int changeNum = 0;
                    for (int k = 0; k < 4; k++)
                        if (i != k)
                            changeNum += digit[k] * pow(10, 3 - k);
                        else
                            changeNum += j * pow(10, 3 - k);
                    if (minFactor[changeNum] == changeNum && cache[changeNum] == 0) {
                        cache[changeNum] = cache[curNum] + 1;
                        q.push(changeNum);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int test_case;
    cin >> test_case;
    eratosthenes();
    for (int i = 0; i < test_case; i++)
    {
        cin >> start >> destination;
        int result = BFS();
        if (result == -1)
            cout << "Impossible" << endl;
        else
            cout << result << endl;
    }
    return 0;
}

