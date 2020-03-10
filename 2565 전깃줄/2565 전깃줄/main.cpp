#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct location{
    int one;
    int two;
}Location;
bool compare(Location a,Location b){
    return a.one<b.one;
}
int main(){
    int n,i,j,num1,num2,result=0;
    cin>>n;
    int dp[102];
    Location loc;
    vector<Location> v;
    for(i=0;i<n;i++){
        cin>>num1>>num2;
        loc.one = num1;
        loc.two = num2;
        v.push_back(loc);
    }
    sort(v.begin(),v.end(),compare);
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(i=1;i<n;i++){
        int count=0;
        for(j=0;j<i;j++){
            if(v[i].two>v[j].two)
                count=max(count,dp[j]);
        }
        dp[i]=count+1;
        result=max(result,dp[i]);
    }
    cout<<n-result<<endl;
}
