#include<iostream>
using namespace std;
int d[101][101][2];
int main()
{
    int T, n, k;
    cin>>T;
    cout<<"\n";
    d[1][0][1] = 1;
    d[1][0][0] = 1;
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            d[i][j][0] = d[i-1][j][0] + d[i-1][j][1]; // 마지막이 0일때
            d[i][j][1] = d[i-1][j-1][1] + d[i-1][j][0];// 마지막이 1일때
        }
    }
    for(int i = 0; i < T; i++)
    {
        cin>>n>>k;
        cout<<d[n][k][0] + d[n][k][1]<<"\n";
    }
}