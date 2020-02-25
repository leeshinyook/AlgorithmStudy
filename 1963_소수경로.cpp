#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
int main(){
    int arr[10000],visit[10000],count[10000],i,j;
    memset(arr,0,sizeof(arr));
    for(i=2;i<10000;i++){
        if (arr[i]==0){
            for(j=2;j*i<10000;j++){
                arr[j*i]=1;
            }
        }
    }
    for(i=0;i<1000;i++){
        arr[i]=1;
    }
    int num1,num2,t,number;
    cin>>t;
    for(i=0;i<t;i++){
        memset(visit,0,sizeof(visit));
        memset(count,-1,sizeof(count));
        cin>>num1>>num2;
        queue<int> q;
        visit[num1]=1;
        count[num1]=0;
        q.push(num1);
        while(!q.empty()){
            for(j=0;j<10;j++){
                number=q.front()-q.front()%10+j;
                if(arr[number]==0&&visit[number]==0){
                    q.push(number);
                    visit[number]=1;
                    count[number]=count[q.front()]+1;
                }
                number=q.front()-q.front()%100+q.front()%10+10*j;
                if(arr[number]==0&&visit[number]==0){
                    q.push(number);
                    visit[number]=1;
                    count[number]=count[q.front()]+1;
                }
                number=q.front()-q.front()%1000+q.front()%100+100*j;
                if(arr[number]==0&&visit[number]==0){
                    q.push(number);
                    visit[number]=1;
                    count[number]=count[q.front()]+1;
                }
                number=q.front()%1000+1000*j;
                if(arr[number]==0&&visit[number]==0){
                    q.push(number);
                    visit[number]=1;
                    count[number]=count[q.front()]+1;
                }
            }
            q.pop();
            if(visit[num2]==1)
                break;
        }
        if(visit[num2]==1)
            cout<<count[num2]<<endl;
        else
            cout<<"Impossible"<<endl;
    }
}
