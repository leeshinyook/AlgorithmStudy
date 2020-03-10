#include<iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long dp[n+1];
    int i,j;
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(i=3;i<=n;i++){
        dp[i]=dp[i-1]+1;
        for(j=1;j<=i-2;j++){
            dp[i]=max(dp[i],dp[i-j-2]*(j+1));
        }
    }
    cout<<dp[n]<<endl;;
}
