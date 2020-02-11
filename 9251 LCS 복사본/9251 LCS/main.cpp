#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char first[1000],second[1000];
int main(){
    memset(first,' ',sizeof(first));
    memset(second,' ',sizeof(second));
    cin>>first>>second;
    int i,j,count[1001][1001];
    for(i=0;i<1001;i++){
        memset(count[i],0,sizeof(count[i]));
    }
    for(i=0;second[i]!=' ';i++){
        for(j=0;first[j]!=' ';j++){
            if(first[j]==second[i]){
                count[i+1][j+1]=count[i][j]+1;
            }
            else
                count[i+1][j+1]=max(count[i][j+1],count[i+1][j]);
        }
    }
    for(i=0;second[i]!=' ';i++){
        for(j=0;first[j]!=' ';j++){
            if(second[i+1]==' '&&first[j+1]==' ')
            cout<<count[i+1][j];
        }
    }
}
