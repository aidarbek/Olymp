#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main ()
{
  freopen ("koki.in","r",stdin);
  freopen ("koki.out","w",stdout);
  int n;
  cin>>n;
if(n==3) {cout<<"1";return 0;}
if(n==5) {cout<<"1";return 0;}

  if((n%5)%3==0) {cout<<n/5+(n-(n/5)*5)/3;return 0;}else
  if((n%3)%5==0) {cout<<n/3+(n/3)/5;return 0;}else
  if(n%5==0) {cout<<n/5;return 0;}else
  if(n%3==0) {cout<<n/3;return 0;}
  else cout<<"-1";

  return 0;
}
