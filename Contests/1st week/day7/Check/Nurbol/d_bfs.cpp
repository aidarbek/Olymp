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
bool can,used[50][50];
int i,j,qi,qj,w[2500],wn,ans;
char maze[50][50];
int cost[50][50],postx,posty,x,y,tox,toy;

int Kwki,cnt;
int h,t,qx[5000001],qy[5000001];

void bfs()
{
 h=0; qx[t=1]=postx; qy[t=1]=posty;
 while(h<t){
  h++;
  for(int dx=-1;dx<2;dx++)
  for(int dy=-1;dy<2;dy++){
   if(!dx && !dy) continue;
   tox = qx[h]+dx; toy = qy[h]+dy;
  
   if(in(tox,toy) && !used[tox][toy] && w[i]<=cost[tox][toy] && cost[tox][toy]<=w[mid]){
    if(maze[tox][toy] == 'K') cnt++;
    t++, qx[t]=tox, qy[t]=toy, used[tox][toy]=1;
   }
  }
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
   if(maze[i][j]=='K')
    Kwki++;
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
  
    cnt = 0;
    bfs();
    
    if(cnt == Kwki) r=mid;
    else l=mid+1;
   }
  }

  // check
  mid = l;
  if(w[mid]>=cost[postx][posty]){
   memset(used,0,sizeof(used));
   
   cnt = 0; bfs();
   
   if(cnt == Kwki)
    ans = min(ans, w[l]-w[i]);
  }

  // fprintf(stderr, "%d %d\n", w[i],w[l]);
 }

 printf("%d", ans);

 return 0;
}