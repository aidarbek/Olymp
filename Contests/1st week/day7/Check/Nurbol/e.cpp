#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

bool used[300001];
int to[300001],n,x,last,i,j,op,m;
bool cycle;

void dfs(int v){
 used[v] = true;
 last = v;
 if(used[to[v]])
  cycle=1;
 if(to[v] && !used[to[v]]){
  dfs(to[v]);
 }
}


int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d", &n);
 for(i=1;i<=n;i++)
  scanf("%d", &to[i]);
 scanf("%d", &m);

 for(i=1;i<=m;i++){
  scanf("%d %d", &op,&x);
  if(op==1){
   cycle = 0;
   for(j=1;j<=n;j++) used[j]=0;
   dfs(x);
   if(cycle) printf("CIKLUS");
   else printf("%d", last);
   printf("\n");
  } else to[x]=0;
 }

 return 0;
}