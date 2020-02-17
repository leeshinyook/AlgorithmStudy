#include<iostream>
#include<queue>
#include<functional>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int>> q;
    int n,i,j,num,count=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&num);
            if(count<n){
                q.push(num);
                count+=1;
            }
            else if(num>q.top()){
                q.push(num);
                q.pop();
            }
        }
    }
    printf("%d",q.top());
}

