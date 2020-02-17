#include<iostream>
#include<stdlib.h>
using namespace std;
int range,n,m,c=0;
typedef struct location{
    int x;
    int y;
    int r;
}Location;
void castle(int num[3],int arr[][15],int funcount){
    int i,j,k;
    location loc[3];
    for(i=0;i<3;i++){
        loc[i].r=range+1;
        loc[i].x=m+1;
        loc[i].y=n+1;
    }
    for(i=funcount-1;i>=funcount-range;i--){
        for(j=0;j<m;j++){
            for(k=0;k<3;k++){
                if(arr[i][j]==1&&(funcount-i)+abs(num[k]-j)<=range){
                    if((funcount-i)+abs(num[k]-j)==loc[k].r&&j<loc[k].x){
                        loc[k].r=(funcount-i)+abs(num[k]-j);
                        loc[k].x=j;
                        loc[k].y=i;
                    }
                    else if((funcount-i)+abs(num[k]-j)<loc[k].r){
                        loc[k].r=(funcount-i)+abs(num[k]-j);
                        loc[k].x=j;
                        loc[k].y=i;
                    }
                }
            }
        }
    }
    for(i=0;i<3;i++){
        if(loc[i].r!=range+1&&arr[loc[i].y][loc[i].x]==1){
            arr[loc[i].y][loc[i].x]=0;
            c+=1;
        }
    }
    if(funcount>=1){
        castle(num,arr,funcount-1);
    }
}
void savearr(int arr[][15],int save[][15]){
    int i,j;
    for(i=0;i<16;i++){
        for(j=0;j<15;j++){
            save[i][j]=arr[i][j];
        }
    }
}
int main(){
    int i,j,k,large=0;
    int arr[16][15],save[16][15];
    scanf("%d%d%d",&n,&m,&range);
    for(i=0;i<16;i++){
        for(j=0;j<15;j++){
            arr[i][j]=0;
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<m;i++){
        for(j=i+1;j<m;j++){
            for(k=j+1;k<m;k++){
                int num[3]={i,j,k};
                savearr(arr,save);
                castle(num,arr,n);
                savearr(save,arr);
                large=max(c,large);
                c=0;
            }
        }
    }
    printf("%d",large);
}

