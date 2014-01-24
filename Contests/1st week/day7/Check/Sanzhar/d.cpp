#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
using namespace std;
int n,sx,sy,k,tx,ty,nx,ny,mn[100][100],mx[100][100],tmn,tmx,res=int(2e9),d[100][100],h[100][100],w[100][100];
char a[100][100];
bool u[100][100];
int dx[]={0,1,1,1,0,-1,-1,-1};
int dy[]={-1,-1,0,1,1,1,0,-1};
queue <int> q;
int main() {
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	scanf("%d\n",&n);
	for (int i=1; i<=n; i++)  
	    for (int j=1; j<=n; j++) {
	        cin >> a[i][j]; 
			if (a[i][j]=='P') {
				sx=i;
				sy=j;
			}
			if (a[i][j]=='K') k++;   
		}                          
	for (int i=1; i<=n; i++)       
		for (int j=1; j<=n; j++) {
			scanf("%d",&h[i][j]);      
			mn[i][j]=h[i][j];
			mx[i][j]=h[i][j];	
			d[i][j]=int(2e9);
		}                   
	q.push(sx);
	q.push(sy);
	d[sx][sy]=0;
	while (!q.empty()) {
		tx=q.front();
		q.pop();
		ty=q.front();
		q.pop();    
		for (int i=0; i<6; i++) {
			nx=tx+dx[i];
			ny=ty+dy[i];
			if (1<=nx&&nx<=n && 1<=ny&&ny<=n) {
				tmn=min(mn[tx][ty],h[nx][ny]);
				tmx=max(mx[tx][ty],h[nx][ny]);  
				if (tmx-tmn<d[nx][ny] || !u[nx][ny]) {
					u[nx][ny]=1;
					d[nx][ny]=tmx-tmn;
					w[nx][ny]=w[tx][ty]+(a[nx][ny]=='K' ? 1 : 0);
					mn[nx][ny]=tmn;
					mx[nx][ny]=tmx;
					q.push(nx);
					q.push(ny);
				}
			}
		}	
	}                                
	for (int i=1; i<=n; i++)             {
		for (int j=1; j<=n; j++) {
			cerr<<d[i][j]<<" ";
			if (w[i][j]==k) 
				if (res>h[i][j]) res=d[i][j];   
			}                cerr<<"\n";}
	printf("%d",res);
	return 0;
}
