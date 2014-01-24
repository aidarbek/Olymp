#include <iostream>
#include <string>
#include <string.h>
#include <queue>
#define MAXN 100000
using namespace std;
int a[1000][1000];
bool u[1000][1000];
int n,m,x,y;
string s;
queue<int> qx;
queue<int> qy;
bool comp(int x1, int y1)
{
	if(x1 >=1 && x1<=m && y1>=1 && y1<=n) return 1;
	else return 0;
}
int main()
{
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	cin>>n>>m;
	cin>>y>>x;   
	bool error = 0;
	for(int i=1;i<=n;i++)
	{              
		cin>>s;
		for(int j=0;j<m;j++)
		{
			if(s[j]=='0') a[i][j+1] = -1;
			else a[i][j+1] = MAXN;
		}
	}	
	if(a[y][x] == -1) 
	{
		cout<<"No solution";
		return 0;
	}
	a[y][x] = 0; 
	u[y][x] = 1;
	qy.push(y);
	qx.push(x);
	x = 0;
	y = 0;
	int min1 = MAXN;
	while(!qx.empty() && !qy.empty())
	{
		x = qx.front();
		qx.pop();
		y = qy.front();
		qy.pop();
		if(comp(x,y+1) && a[y+1][x]!=-1 && !u[y+1][x])
		{    
			a[y+1][x] = min(a[y+1][x], a[y][x]+1);
			qx.push(x);
			qy.push(y+1);
			u[y+1][x] = 1;
		}
		if(comp(x,y-1) && a[y-1][x]!=-1 && !u[y-1][x])
		{    
			a[y-1][x] = min(a[y-1][x], a[y][x]+1);
			qx.push(x);
			qy.push(y-1);
			u[y-1][x] =  1;
		}

		if(comp(x+1,y) && a[y][x+1]!=-1 && !u[y][x+1])
		{    
			u[y][x+1] = 1;
			a[y][x+1] = min(a[y][x+1], a[y][x]+1);
			qx.push(x+1);
			qy.push(y);
		}
		if(comp(x-1,y) && a[y][x-1]!=-1 && !u[y][x-1])
		{    
			u[y][x-1] = 1;
			a[y][x-1] = min(a[y][x-1], a[y][x]+1);
			qx.push(x-1);
			qy.push(y);
		}
		if(y%2==0)
		{
			if(comp(x+1,y+1) && a[y+1][x+1]!=MAXN && !u[y+1][x+1])
			{    
				u[y+1][x+1] = 1;
				a[y+1][x+1] = min(a[y+1][x+1], a[y][x]+1);
				qx.push(x+1);
				qy.push(y+1);
			}	
			if(comp(x+1,y-1) && a[y-1][x+1]!=MAXN && !u[y-1][x+1]) 
			{    
				u[y-1][x+1] = 1;
				a[y-1][x+1] = min(a[y-1][x+1], a[y][x]+1);
				qx.push(x+1);
				qy.push(y-1);
			}
		}
		else
		{
			if(comp(x-1,y-1) && a[y-1][x-1]!=MAXN && !u[y-1][x-1])
			{    
				u[y-1][x-1] = 1;
				a[y-1][x-1] = min(a[y-1][x-1], a[y][x]+1);
				qx.push(x-1);
				qy.push(y-1);
			}	
			if(comp(x-1,y+1) && a[y+1][x-1]!=MAXN && !u[y+1][x-1])
			{    
				u[y+1][x-1] = 1;
				a[y+1][x-1] = min(a[y+1][x-1], a[y][x]+1);
				qx.push(x-1);
				qy.push(y+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		 if(a[1][i] != MAXN) min1 = min(min1, a[1][i]);
		 if(a[i][1] != MAXN) min1 = min(min1, a[i][1]);

		 if(a[n][i] != MAXN) min1 = min(min1, a[n][i]);
		 if(a[i][n] != MAXN) min1 = min(min1, a[i][n]);
		 
	}
	if(min1 == MAXN) cout<<"No solution";
	else cout<<min1+1;
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
