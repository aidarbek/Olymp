#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n,ans,five;

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 cin >> n;
 ans = 5001;
 while(true){
  if(n % 3 == 0)
   ans = min(ans, n/3+five);
  if(!n || n == 3) break;
  if(n >= 5)
   n-=5, five++;
  if(n < 5 && n%3) break;
 }

 if(ans == 5001) printf("-1");
 else printf("%d", ans);

 return 0;
}