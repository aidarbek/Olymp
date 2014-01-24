#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
using namespace std;
const int INF=100001;
char a[26];
int n,k,s,i;
char ch;
string ans;
int main(){
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
     cin>>n>>k;
     int x=0;
     memset(a,'-',n+1);
     for(i=1;i<=k;i++){
          cin>>s>>ch;      
          x=(x+s)%n;
          if(a[x]!='-' && a[x]!=ch){
    		cout<<"!";
          return 0;     
          }
		else {
		 a[x]=ch;
          }
       
     }
     ans+=a[x];
     for(i=x-1;i!=x;i--){
        if(i==-1){
        i=n-1;
        }
        if(a[i]!='-')
        ans+=a[i];
        else
        ans+='?';
     } 

     cout<<ans;
return 0;}