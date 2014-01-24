#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

long long sum;
int l,r,x,c,Do,a[10000001],n,Q,i;

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d %d", &n,&Q);
 for(i=1;i<=n;i++)
  scanf("%d", &a[i]);
 while(Q--){
  scanf("%d", &Do);
  if(Do==1){
   scanf("%d %d %d", &l,&r,&x);
   for(i=l;i<=r;i++)
    a[i]=x;
  }
  if(Do==2){
   scanf("%d %d %d", &l,&r,&x);
   for(i=l;i<=r;i++)
    a[i]+=(i-l+1)*x;
  }
  if(Do==3){
   scanf("%d %d", &c,&x);
   for(i=n+1;i>c;i--)
    a[i]=a[i-1];
   a[c]=x;
   n++;
  }
  if(Do==4){
   scanf("%d %d", &l,&r);
   sum=0;
   for(i=l;i<=r;i++)
    sum+=a[i];
   cout<<sum<<"\n";
  }
 } 

 return 0;
}