#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n,p,mid,l,r,i,str,fret,sz[10];
int last[10],a[10][300001],ans;

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d %d", &n,&p);
 for(i=1;i<=n;i++){
  scanf("%d %d", &str,&fret);
  if(last[str] == fret)
   continue;
  else if(fret>last[str]){
   last[str]=fret;
   a[str][++sz[str]]=fret;
   ans++;
  } 
  else{
   l=1; r=sz[str];
   while(l<r){
    mid=(l+r+1)/2;
    if(a[str][mid]>fret)
     r=mid-1;
    else l=mid;
   }
   if(a[str][l]>fret) l--;

   ans+=(sz[str]-l);
   sz[str] = l;

   if(!l)
    a[str][++sz[str]]=fret,ans++;
   else if(a[str][l] != fret)
    a[str][++sz[str]]=fret,ans++;          
   
   last[str]=fret;
  }
 }

 printf("%d", ans);

 return 0;
}