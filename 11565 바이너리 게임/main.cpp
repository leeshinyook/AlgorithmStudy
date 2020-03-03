#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char str[1000];
    int i,count1=0,count2=0;
    scanf("%s",str);
    for(i=0;str[i]!=NULL;i++){
        if(str[i]=='1')
            count1+=1;
    }
    memset(str,'0',sizeof(str));
    scanf("%s",str);
    for(i=0;str[i]!=NULL;i++){
        if(str[i]=='1')
            count2+=1;
    }
    if(count1%2==1)
        count1+=1;
    if(count1>=count2)
        cout<<"VICTORY"<<endl;
    else
        cout<<"DEFEAT"<<endl;
}
