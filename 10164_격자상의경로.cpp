#include<iostream>
using namespace std;
int main(){
    int n,m,k,i,j,x=0,y=0;
    cin>>n>>m>>k;
    int arr[n][m];
    if(k!=0){
        if(k%m==0){
            x=m-1;
            y=k/m-1;
        }
        else{
            x=k%m-1;
            y=k/m;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            arr[i][j]=0;
        }
    }
    for(i=0;i<=y;i++){
        for(j=0;j<=x;j++){
            if(i==0&&j==0)
                arr[i][j]=1;
            else if(i==0)
                arr[i][j]=arr[i][j-1];
            else if(j==0)
                arr[i][j]=arr[i-1][j];
            else
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    for(i=y;i<n;i++){
        for(j=x;j<m;j++){
            if(i==y&&j==x){
                arr[i][j]+=0;
            }
            else if(i==y){
                arr[i][j]=arr[i][j-1];
            }
            else if(j==x)
                arr[i][j]=arr[i-1][j];
            else
                arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
    }
    cout<<arr[n-1][m-1]<<endl;
}
