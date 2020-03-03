#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main(){
    int check[1003002],i,j,num,count=1,size,result,number;
    memset(check,0,sizeof(check));
    for(i=2;i<=1003001;i++){
        if(check[i]==0){
            for(j=2;j*i<=1003001;j++)
                check[j*i]=1;
        }
    }
    check[0]=1;
    check[1]=1;
    cin>>num;
    for(j=num;j<=1003001;j++){
        for(i=0;pow(10,i)<=j;i++){
            size=i+1;
        }
        count=0;
        number=j;
        result=0;
        int arr[size];
        memset(arr,0,sizeof(arr));
        while(number!=0){
            arr[count]=number%10;
            number/=10;
            count++;
        }
        for(i=0;i<size/2;i++){
            if(arr[i]!=arr[size-i-1]){
                result=-1;
                break;
            }
        }
        if(result==0&&check[j]==0){
            cout<<j<<endl;
            break;
        }
    }
}

