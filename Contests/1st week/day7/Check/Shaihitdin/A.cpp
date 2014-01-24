#include<iostream>
#include<stdio.h>
using namespace std;
const int INF=100001;
int d[5001],n,i;
int main(){
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++){
    d[i]=INF;
    }
    d[5]=1;
    d[3]=1;
    for(i=6;i<=n;i++){
        d[i]=min(d[i-5],d[i-3])+1; 
    }
    if(d[n]>=INF)
    cout<<-1;
    else
    cout<<d[n];
return 0;}