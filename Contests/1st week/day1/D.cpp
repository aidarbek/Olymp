#include <iostream>
#include <queue>
#include <stdio.h>
#include <cstdlib>
using namespace std;
char s[1000];
char a[10000][10000];
int  d[10000][10000];
int  b[10000][10000];
bool u[10000][10000];
int  r,c;
int  fx,fy;
int  sx,sy;
bool pass(int x,int y)
{
	if(x>0 && x<=r && y>0 && y<=c) if( b[x][y]!=-1) if(a[x][y]=='.' || a[x][y]=='D') return 1;
	else return 0;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	queue<int> x;
	queue<int> y;
	cin>>r>>c;
	int t = 0;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='D')
			{
				fx = i;
				fy = j;
			}
			if(a[i][j]=='S')
			{
				sx = i;
				sy = j;
			}
			if(a[i][j]=='*' || a[i][j]=='X')
			{
				b[i][j] = -1;
			}
		}       

	x.push(sx);
	y.push(sy);
	int vx,vy;
	while(!x.empty() && !y.empty())
	{
		vx = x.front();
		x.pop();
		vy = y.front();
		y.pop();
		u[vx][vy] = 1;
		if(b[vx][vy]!=-1)
		{
			
			if(pass(vx+1,vy) && !u[vx+1][vy]) {b[vx+1][vy] = b[vx][vy]+1;
								x.push(vx+1);y.push(vy);}
			if(pass(vx-1,vy) && !u[vx-1][vy]) {b[vx-1][vy] = b[vx][vy]+1;
								x.push(vx-1);y.push(vy);}
			if(pass(vx,vy+1) && !u[vx][vy+1]) {b[vx][vy+1] = b[vx][vy]+1;
								x.push(vx);y.push(vy+1);}
			if(pass(vx,vy-1) && !u[vx][vy-1]) {b[vx][vy-1] = b[vx][vy]+1;
								x.push(vx);y.push(vy-1);}
			/*if(!u[b[vx][vy]])
			{
				u[b[vx][vy]] = 1;
				for(int i=1;i<=r;i++)
				{
					for(int j=1;j<=c;j++)
					{
						/*if(a[i][j]=='*')
						{
							 if(pass(i,j+1)) {a[i][j+1]='*';b[i][j+1]=-1;}
							 if(pass(i+1,j)) {a[i+1][j]='*';b[i+1][j]=-1;}
							 if(pass(i-1,j)) {a[i-1][j]='*';b[i-1][j]=-1;}
							 if(pass(i,j-1)) {a[i][j-1]='*';b[i][j-1]=-1;} 
						}   
					}

				}

			}*/
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
