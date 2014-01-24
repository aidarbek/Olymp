#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<utility>
#include<cstring>
#include<algorithm>

using namespace std;

#define inf (1<<30)

int n;

bool in(int x,int y){
 return (0<=x && x<n && 0<=y && y<n);
}

bool good,can,used[50][50];
int l,r,i,j,L,R,qi,qj,mid;
char maze[50][50];
int cost[50][50],postx,posty,x,y,tox,toy;

void dfs(int vx,int vy){
 used[vx][vy] = 1;
 for(int dx=-1;dx<2;dx++)
 for(int dy=-1;dy<2;dy++){
  if(!dx && !dy) continue;
  tox = vx+dx; toy = vy+dy;
  
  if(in(tox,toy) && !used[tox][toy] && L<=cost[tox][toy] && cost[tox][toy]<=R)
   dfs(tox,toy);
 }
}

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d\n", &n);
 for(i=0;i<n;i++)
  scanf("%s\n", &maze[i]);
 for(i=0;i<n;i++){
  for(j=0;j<n;j++){
   scanf("%d ", &cost[i][j]);
   if(maze[i][j]=='P')
    postx=i,posty=j;
  }
  scanf("\n");
 }

 l=0; r=1000000;
 while(l<r){
  mid=(l+r)/2; good = 0;

  for(i=1;i<=1000000;i++){
   L=i; R=i+mid;
   if(!(L<=cost[postx][posty] && cost[postx][posty]<=R))
    continue;
   
   for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++) used[qi][qj]=0;
   
   dfs(postx,posty);

   can=1;
   for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++)
    if(!used[qi][qj] && maze[qi][qj]=='K')
     can=0;

   if(can) good = 1;
  }
  if(good) r=mid;
  else l=mid+1;
 }

 printf("%d\n", l);

 return 0;
}