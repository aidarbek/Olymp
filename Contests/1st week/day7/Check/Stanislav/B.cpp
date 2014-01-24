#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
int b[101];
char l[101];
int main ()
{

freopen ("koki.in","r",stdin);
freopen ("koki.out","w",stdout);
int mx=0,n,m,j=0,r=0;
char h;
cin>>n;
int k=0;
char a[n];
cin>>m;
for(int i=1;i<=m;i++){

 cin>>b[i];
mx+=b[i];

    while (j<1)
    {
    cin>>h;
    j=1;
    }
    j=0;
    k=mx;

while(k>n){k=abs(n-k);}

if(a[k]!=0)r++;
a[k]=h;
               }
               if(r!=0) {cout<<"-1";return 0;}
int v=1;
for(int y=k;y<=n;y++)
{
  //cout<<a[y]<<" ";
  l[v]=a[y];
  v++;
}
for(int i=1;i<=k;i++)
{
  //cout<<a[i]<<" ";
 l[v]=a[i];
  v++;
}
for(int f=v-1;f>=2;f--)
{
  if(int(l[f])==0) cout<<"?";
    else
     cout<<l[f];
}
  return 0;
}

