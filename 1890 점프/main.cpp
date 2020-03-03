#include<iostream>
using namespace std;
int arr[101][101],num;
long long check[101][101];
int main(){
    int i,j;
    cin>>num;
    for(i=1;i<=num;i++){
        for(j=1;j<=num;j++){
            scanf("%d",&arr[i][j]);
            check[i][j]=0;
        }
    }
    check[1][1]=1;
    for(i=1;i<=num;i++){
        for(j=1;j<=num;j++){
            if(i+arr[i][j]<=num&&arr[i][j]!=0){
                check[i+arr[i][j]][j]+=check[i][j];
            }
            if(j+arr[i][j]<=num&&arr[i][j]!=0){
                check[i][j+arr[i][j]]+=check[i][j];
            }
        }
    }
    cout<<check[num][num];
}
