#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int arr[25][25];
int check_home(int n, int row,int col){
    int count=1;
    queue<pair<int,int>> q;
    pair<int,int>p1=make_pair(row,col);
    q.push(p1);
    arr[row][col]=0;
    while(!q.empty()){
        if(arr[row][col-1]==1&&col-1>=0){
            count+=1;
            p1=make_pair(row,col-1);
            q.push(p1);
            arr[row][col-1]=0;
        }
        if(arr[row][col+1]==1&&col+1<n){
            count+=1;
            p1=make_pair(row,col+1);
            q.push(p1);
            arr[row][col+1]=0;
        }
        if(arr[row-1][col]==1&&row-1>=0){
            count+=1;
            p1=make_pair(row-1,col);
            q.push(p1);
            arr[row-1][col]=0;
        }
        if(arr[row+1][col]==1&&row+1<n){
            count+=1;
            p1=make_pair(row+1,col);
            q.push(p1);
            arr[row+1][col]=0;
        }
        q.pop();
        p1=q.front();
        row=p1.first;
        col=p1.second;
    }
    return count;
}
int main(){
    int n,i,j;
    vector<int> result;
    cin>>n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(arr[i][j]==1)
                result.push_back(check_home(n,i,j));
        }
    }
    sort(result.begin(),result.end());
    vector<int>::size_type size=result.size();
    cout<<size<<endl;
    for(vector<int>::iterator iter=result.begin();iter!=result.end();iter++){
        cout<<*iter<<endl;
    }
}
