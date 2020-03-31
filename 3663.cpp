//
// Created by 0864h on 2020-03-24.
//
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
int main()
{
    int n,i,j,s,e,val=0,count,sft1,sft2,c,check,ans=0,a,b;
    char str[1000];
    scanf("%d", &n);
    s = 'A'; e = 'Z';
    for(i=0;i<n;i++) {
        scanf("%s\n", str);
        queue<char> q;
        stack<char> st;
        count=0;sft1=-1;sft2=0;c=0,check=0,a=0,b=0;
        for (j = 0; str[j]; j++) {
            q.push(str[j]);
            st.push(str[j]);
            val = str[j];
            if(str[j]=='A')
                continue;
            if(val-s<=13)
            {
                count += (val-s);
            }
            else if(val-s>13)
            {
                count += (e-val+1);
            }
        }
        while(!st.empty()) {
            if (st.top() == 'A') {
                sft1++;
                st.pop();
            } else break;
        }
        while(!q.empty())
        {
            if(check==1 && q.front()!='A')
                break;
            c++;
            if(q.front()=='A' && check==0)
            {
                if(c<2)
                {
                    sft2=2;check+=1;
                }
                else
                {
                    sft2=c; check+=1;
                }
            }
            q.pop();
        }
        if(sft1==j-1)
            a = 0;
        else if(sft1==-1)
            a = j-1;
        else a = j-2-sft1;
        if(check==0)
            b = j-1;
        if(check==1 && c==j)
            b = j-1-sft2;
        else if(check==1 && (sft2-2)*2+j-c < 2*(j-c+1)-1+sft2-1)
        {
            if((sft2-2)*2+j-c < j-1)
                b = (sft2-2)*2+j-c;
            else b = j-1;
        }
        else if(check==1 && 2*(j-c+1)-1+sft2-1 < (sft2-2)*2+j-c)
        {
            if(2*(j-c-1)-1+sft2-1 < j-1)
                b = 2*(j-c+1)-1+sft2-1;
            else b = j-1;
        }
        if(a > b)
            ans = count + b;
        else ans = count + a;
        printf("%d\n", ans);
    }
}
