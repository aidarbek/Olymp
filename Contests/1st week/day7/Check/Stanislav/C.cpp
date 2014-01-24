#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[10001][1];
int main ()
{
  freopen ("koki.in","r",stdin);
freopen ("koki.out","w",stdout);
  int  n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=2;j++)
    {
      cin>>a[i][j];
    }
  }
  cout<<n+2;
  return 0;
}
