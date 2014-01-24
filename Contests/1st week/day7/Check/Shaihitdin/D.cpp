#include<list>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,i,j,d[51][51];
char a[51][51];
int main(){
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
      cin>>n;
      for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
       cin>>a[i][j];
       }
      }
      for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
        cin>>d[i][j];
        }
      }
      long long mn=9999999,mx=-1000000;
     for(i=1;i<=n;i++){
       for(j=1;j<=n;j++){
         if(a[i][j]=='P' || a[i][j]=='K')
         {if(mn>d[i][j])  mn=d[i][j];
          if(mx<d[i][j])  mx=d[i][j];
         }
       }
     
     }
     cout<<mx-mn;
return 0;}