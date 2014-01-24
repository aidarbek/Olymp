#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
char a[10001][10001];
int  d[10001]; 
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int r,c;
	cin>>n>>m;
	r = n*5+1;
	c = m*5+1;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>a[i][j];
		}
	}
	int x,y;
	int q = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			q = 0;
			x = (i-1)*5+2;
			y = (j-1)*5+2;
			for(int k=0;k<4;k++)
			{
				if(a[x+k][y]=='*') q++;
			}
			d[q]++;
		}
	}
	for(int i=0;i<5;i++) cout<<d[i]<<" ";
	return 0;
}
