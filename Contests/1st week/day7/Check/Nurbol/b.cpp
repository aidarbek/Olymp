#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int i,n,k,t,last;
char a[30],c;

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d %d\n", &n,&k);
 for(i=0;i<n;i++)
  a[i]='?';
 i=-1;
 while(k--){
  scanf("%d %c\n", &t,&c);
  i=(i+t)%n;
  if(a[i]!='?' && a[i]!=c){
   printf("!");
   return 0;
  } 
  
  a[i]=c; last=i;
 }

 for(i=0;i<n;i++){
  printf("%c", a[last]);
  last--;
  if(last<0) last=n-1;
 }

 return 0;
}