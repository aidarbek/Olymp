#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[1001][1001];
string  s[1001];
int main ()
{
  freopen ("koki.in","r",stdin);
freopen ("koki.out","w",stdout);
  int  n;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>s[i];
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=n;j++)
    {
      cin>>a[i][j];
    }
  }
  cout<<n;
  return 0;
}
