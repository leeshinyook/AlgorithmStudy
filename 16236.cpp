//
// Created by 0864h on 2020-02-08.
//
#include<iostream>
#include<queue>
using namespace std;
int dis[21][21], int sec[21][21];
bool check[21][21], eat[21][21];
int dx[] = {-1, 1 ,0, 0};//상 하 좌 우
int dy[] = {0, 0, -1, 1};//상 하 좌 우
int bfs(&dis, int x, int y, int size)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));//시작점 큐에 푸시
    check[x][y] = true;
    sec[x][y] = 0;
    while(!q.empty())
    {
        tie(x,y) = q.front();
        q.pop();
        for (int k = 0; k<4; k++)
        {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(dis[nx][ny]<=v && check[nx][ny]== false)
            {
                sec[nx][ny] = sec[x][y] + 1;
                check[nx][ny] = true;
            }
        }
    }
}
 int main()
{
    int i,j,x,y,n,count=0,size=2,exp=0;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>dis[i][j];
            if(dis[i][j]==9)
            {
                tie(x,y) = make_pair(i,j);
                dis[i][j]=0;
            }
        }
    }
    cout<<bfs(x,y,n,2);
} 
