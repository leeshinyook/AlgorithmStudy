#include<iostream>
#include<queue>
using namespace std;
typedef struct location{
    int x;
    int y;
}Location;
int main(){
    int n,k,i,j,row,col,n2,count=0,tail1=0,tail2=0;
    queue<Location> q;
    Location location;
    cin>>n>>k;
    int arr[n][n];
    char dir=0;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    arr[0][0]=2;
    for(i=0;i<k;i++){
        cin>>row>>col;
        arr[row-1][col-1]=1;
    }
    cin>>n2;
    int time[n2];
    char direction[n2];
    for(i=0;i<n2;i++){
        cin>>time[i]>>direction[i];
    }
    i=0;
    j=0;
    k=0;
    location.x=0;
    location.y=0;
    q.push(location);
    while(1){
        if(i==n||j==n||i<0||j<0){
            break;
        }
        if(time[k]==count){
            if(direction[k]=='D')
                dir+=1;
            else
                dir-=1;
            if(dir<0)
                dir=3;
            else if(dir>3)
                dir=0;
            k+=1;
        }
        if(dir==0){
            j+=1;
            count+=1;
            if(arr[i][j]==2)
                break;
        }
        else if(dir==1){
            i+=1;
            count+=1;
            if(arr[i][j]==2)
                break;
        }
        else if(dir==2){
            j-=1;
            count+=1;
            if(arr[i][j]==2)
                break;
        }
        else if(dir==3){
            i-=1;
            count+=1;
            if(arr[i][j]==2)
                break;
        }
        if(arr[i][j]==1){
            arr[tail1][tail2]=2;
        }
        else{
            arr[tail1][tail2]=0;
            q.pop();
        }
        arr[i][j]=2;
        location.x=i;
        location.y=j;
        q.push(location);
        tail1=q.front().x;
        tail2=q.front().y;
    }
    cout<<count<<endl;
}

