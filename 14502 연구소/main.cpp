#include<iostream>
#include<queue>
#include<algorithm>
typedef struct location{
    int x;
    int y;
}Location;
using namespace std;
int arr[8][8],n,m,large=0;
void bfs(){
    int visit[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visit[i][j]=0;
        }
    }
    int i,j,count=0,result=0;
    Location loc;
    queue<Location> q;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            int virus=0;
            if(arr[i][j]==0&&visit[i][j]==0){
                loc.x=i;
                loc.y=j;
                visit[i][j]=1;
                count+=1;
                q.push(loc);
                while(!q.empty()){
                    if (visit[q.front().x+1][q.front().y]==0&&q.front().x<n-1){
                        if(arr[q.front().x+1][q.front().y]==0){
                            visit[q.front().x+1][q.front().y]=1;
                            loc.x=q.front().x+1;
                            loc.y=q.front().y;
                            count+=1;
                            q.push(loc);
                        }
                        if(arr[q.front().x+1][q.front().y]==2)
                            virus = 1;
                    }
                    if (visit[q.front().x][q.front().y+1]==0&&q.front().y<m-1){
                        if(arr[q.front().x][q.front().y+1]==0){
                            visit[q.front().x][q.front().y+1]=1;
                            loc.x=q.front().x;
                            loc.y=q.front().y+1;
                            count+=1;
                            q.push(loc);
                        }
                        if(arr[q.front().x][q.front().y+1]==2)
                            virus =1;
                    }
                    if (visit[q.front().x-1][q.front().y]==0&&q.front().x>0){
                        if(arr[q.front().x-1][q.front().y]==0){
                            visit[q.front().x-1][q.front().y]=1;
                            loc.x=q.front().x-1;
                            loc.y=q.front().y;
                            count+=1;
                            q.push(loc);
                        }
                        if(arr[q.front().x-1][q.front().y]==2)
                            virus=1;
                    }
                    if (visit[q.front().x][q.front().y-1]==0&&q.front().y>0){
                        if(arr[q.front().x][q.front().y-1]==0){
                            visit[q.front().x][q.front().y-1]=1;
                            loc.x=q.front().x;
                            loc.y=q.front().y-1;
                            count+=1;
                            q.push(loc);
                        }
                        if(arr[q.front().x][q.front().y-1]==2)
                            virus=1;
                    }
                    q.pop();
                }
                if(virus == 0)
                    result+=count;
                virus=0;
                count=0;
            }
        }
    }
    large=max(large,result);
}
void wall(int count){
    if(count==3){
        bfs();
        return;
    }
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]==0){
                arr[i][j]=1;
                wall(count+1);
                arr[i][j]=0;
            }
        }
    }
}
int main(){
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    wall(0);
    cout<<large;
}
