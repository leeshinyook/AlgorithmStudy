//
// Created by 0864h on 2020-04-16.
//
#include<iostream>
#include <string>
using namespace std;
long long d[251];
int main()
{
    int n;
    string str;
    do
    {
        cin>>n;
        d[0] = 1; d[1] = 1; d[2] = 3;
        for(int i = 2; i <= n; i++)
        {
            d[i] = d[i-1] + 2 * d[i-2];
        }
        str = to_string(d[n]);
        cout<<str<<"\n";
    }while(getc(stdin) >= 0);
}