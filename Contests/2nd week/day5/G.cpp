#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <string.h>
using namespace std;
char a[21][100001];
char b[21][100001];
int n,m;
int y;
int border(int v)
{             
	if(v>m) return v%m;
	else return v;
}
int main()
{
	freopen("G.in","r",stdin);
	freopen("G.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}            
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>b[i][j];
		}
	}
	int offset = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=b[i][j])
			{
			  for(int k=offset;k<=m;k++)
			  {        
			  	 y = border(j+k);
			  	 if(b[i][j]==a[i][y])
			  	 {
			  	 	offset = k;
			  	 	break;
			  	 }
			  }
			}          			
		}
	}
	cout<<offset;
	return 0;
}