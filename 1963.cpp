//
// Created by 0864h on 2020-02-23.
//
#include<iostream>
#include<queue>
#include <cstring>
using namespace std;
void pw(int num1, int pn, bool check[], queue<pair<int,int>> q, bool visit[]) {
    int i,j,num=0,count = 0,val;
    if(num1 == pn)
    {
        cout<<0; return;
    }
    else {
        while (!q.empty()) {
            num1 = q.front().second;
            count = q.front().first + 1;
            q.pop();
            for (i = 0; i <= 9; i++) {
                val = num1;
                for (j = 1000; j >= 1; j /= 10) {
                    if (j == 1000) {
                        if (i == 0)
                        {
                            val %= j; continue;
                        }
                        else
                            num = num1 % j + j * i;
                    }
                    else if(j!=1000 && val>=j)
                        num = num1 - val/j*j + j*i;
                    else if(j!=1000 && val<j)//해당자리수 0일때
                        num = num1 + j*i;
                    if (check[num] == false && visit[num]==false)//소수일 경우
                    {
                        q.push(make_pair(count, num));
                        if (num == pn) {
                            cout << q.back().first<<"\n";
                            return;
                        }
                        visit[num] = true;
                    }
                    val %= j;
                }
            }
        }
        cout<<"Impossible";
    }
}
int main()
{
    bool check[10000];
    bool visit[10000];
    queue<pair<int,int>> q;
    queue<pair<int,int>> empty;
    int T,i,j,num1,num2;
    check[2] = true;
    for(i=2;i<=9999;i++)
    {
        for(j=i+i;j<=9999;j+=i)
            check[j] = true;//소수가 아닌 수 체크
    }
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>num1>>num2;
        if(i>=1) {
            q = empty;
            memset(visit, false, sizeof(visit));
        }
        q.push(make_pair(0, num1));
        pw(num1, num2, check, q, visit);
    }
}

