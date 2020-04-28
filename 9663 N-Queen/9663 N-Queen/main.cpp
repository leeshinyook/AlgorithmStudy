#include<iostream>
using namespace std;
int arr[14][14],n,result=0;
bool check(int x,int y){
    int i,j,c=0,dx[4]={1,1,-1,-1},dy[4]={1,-1,1,-1};
    for(i=0;i<n;i++){
        if(arr[i][x]==1||c==1){
            return false;
        }
    }
    for(i=0;i<4;i++){
        j=0;
        if(c==0){
            while(y+dy[i]*j>=0&&y+dy[i]*j<n&&x+dx[i]*j>=0&&x+dx[i]*j<n){
                if(arr[(y+dy[i]*j)][x+dx[i]*j]==1){
                    return false;
                }
                j++;
            }
        }
    }
    return true;
}
void chess(int y){
    int i;
    if(y==n){
        result+=1;
        return;
    }
    for(i=0;i<n;i++){
        if(check(i,y)){
            arr[y][i]=1;
            chess(y+1);
            arr[y][i]=0;
        }
    }
}
int main(){
    int i,j;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    chess(0);
    printf("%d",result);
}
