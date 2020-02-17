#include<iostream>
#include<queue>
using namespace std;
int arr[20][20],t=0,size=2,x,y;
int search(int n,int a,int b){
    queue<int> q1;
    queue<int> q2;
    int count[n][n],visit[n][n],i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            count[i][j]=10001;
            visit[i][j]=0;
        }
    }
    count[a][b]=0;
    visit[a][b]=1;
    q1.push(a);
    q2.push(b);
    while(!q1.empty()){
        if(q1.front()<n-1&&visit[q1.front()+1][q2.front()]==0){
            if(arr[q1.front()+1][q2.front()]==9||arr[q1.front()+1][q2.front()]<=size){
            visit[q1.front()+1][q2.front()]=1;
            q1.push(q1.front()+1);
            q2.push(q2.front());
            count[q1.front()+1][q2.front()]=count[q1.front()][q2.front()]+1;
            }
        }
        if(q2.front()<n-1&&visit[q1.front()][q2.front()+1]==0){
            if(arr[q1.front()][q2.front()+1]==9||arr[q1.front()][q2.front()+1]<=size){
            visit[q1.front()][q2.front()+1]=1;
            q1.push(q1.front());
            q2.push(q2.front()+1);
            count[q1.front()][q2.front()+1]=count[q1.front()][q2.front()]+1;
            }
        }
        if(q1.front()>0&&visit[q1.front()-1][q2.front()]==0){
            if(arr[q1.front()-1][q2.front()]==9||arr[q1.front()-1][q2.front()]<=size){
            visit[q1.front()-1][q2.front()]=1;
            q1.push(q1.front()-1);
            q2.push(q2.front());
            count[q1.front()-1][q2.front()]=count[q1.front()][q2.front()]+1;
            }
        }
        if(q2.front()>0&&visit[q1.front()][q2.front()-1]==0){
            if(arr[q1.front()][q2.front()-1]==9||arr[q1.front()][q2.front()-1]<=size){
            visit[q1.front()][q2.front()-1]=1;
            q1.push(q1.front());
            q2.push(q2.front()-1);
            count[q1.front()][q2.front()-1]=count[q1.front()][q2.front()]+1;
            }
        }
        q1.pop();
        q2.pop();
    }
    return count[x][y];
}
int main(){
    int n,i,j,count=0,num,small,xp=0,yp=0;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                x=i;
                y=j;
            }
        }
    }
    while(1){
        small=10000;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(arr[i][j]<size&&arr[i][j]!=0){
                    num=search(n,i,j);
                    if(small>num){
                        small=num;
                        xp=i;
                        yp=j;
                    }
                    else if(small==num){
                        if(i<xp){
                            xp=i;
                            yp=j;
                        }
                        else if(i==xp&&j<yp){
                            xp=i;
                            yp=j;
                        }
                    }
                    
                }
            }
        }
        if(small==10000){
            break;
        }
        arr[xp][yp]=9;
        arr[x][y]=0;
        x=xp;
        y=yp;
        t+=small;
        count+=1;
        if(count==size){
            size+=1;
            count=0;
        }

    }
    cout<<t<<endl;
}
