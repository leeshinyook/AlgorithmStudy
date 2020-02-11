#include<iostream>
#include<algorithm>
using namespace std;
typedef struct stuff{
    int value;
    int weight;
}Stuff;
int main(){
    int n,k,i,j;
    cin>>n>>k;
    int memo[n+1][k+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            memo[i][j]=0;
        }
    }
    Stuff stuff[n];
    for(i=0;i<n;i++){
        cin>>stuff[i].weight>>stuff[i].value;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            memo[i][j]=memo[i-1][j];
            if(stuff[i-1].weight<=j&&memo[i-1][j-stuff[i-1].weight]+stuff[i-1].value>memo[i][j]){
                memo[i][j]=memo[i-1][j-stuff[i-1].weight]+stuff[i-1].value;
            }
        }
    }
    cout<<memo[n][k]<<endl;
}
