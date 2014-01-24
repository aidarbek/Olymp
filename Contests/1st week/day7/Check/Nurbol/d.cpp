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

int l,r,mid;
bool good,can,used[50][50];
int i,j,qi,qj,w[2500],wn,ans;
char maze[50][50];
int cost[50][50],postx,posty,x,y,tox,toy;

void dfs(int vx,int vy){
 used[vx][vy] = 1;
 for(int dx=-1;dx<2;dx++)
 for(int dy=-1;dy<2;dy++){
  if(!dx && !dy) continue;
  tox = vx+dx; toy = vy+dy;
  
  if(in(tox,toy) && !used[tox][toy] && w[i]<=cost[tox][toy] && cost[tox][toy]<=w[mid])
   dfs(tox,toy);
 }
}

int main(){
 freopen("koki.in","r",stdin);
 freopen("koki.out","w",stdout);

 scanf("%d\n", &n);
 for(i=0;i<n;i++)
  scanf("%s\n", &maze[i]);     

 ans = inf;

 for(i=0;i<n;i++){
  for(j=0;j<n;j++){
   scanf("%d ", &cost[i][j]);
   w[wn++]=cost[i][j];
   if(maze[i][j]=='P')
    postx=i,posty=j;
  }
  scanf("\n");
 }

 sort(w,w+wn);
 wn = unique(w,w+wn)-w;

 for(i=0;i<wn;i++){
  if(w[i]>cost[postx][posty])
   continue;
  
  // cerr<<"[next]\n";
   
  l=i; r=wn-1;

  while(l<r)
  {
   mid=(l+r)/2;
   if(w[mid]<cost[postx][posty]) l=mid+1;
   else {
    for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++) used[qi][qj]=0;
  
    dfs(postx,posty);
    
    good = 1;
    for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++)
     if(!used[qi][qj] && maze[qi][qj]=='K')
      good = 0;

    if(good) r=mid;
    else l=mid+1;
   }
  }

  // check
  mid = l;
  if(w[mid]<cost[postx][posty]) good = 0;
  else {
   for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++) used[qi][qj]=0;
   
   dfs(postx,posty);
   
   good = 1;
   for(qi=0;qi<n;qi++) for(qj=0;qj<n;qj++)
    if(!used[qi][qj] && maze[qi][qj]=='K')
     good = 0;
   }

  // fprintf(stderr, "%d %d\n", w[i],w[l]);

  if(good){
   // cerr << "good\n";
   ans = min(ans, w[l]-w[i]);
  }  
 }

 printf("%d", ans);

 return 0;
}