#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int a[10000][10000];
int b[10000];
bool u[10000];
int ans;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i][0];
		for(int j=1;j<=a[i][0];j++)
		{
			cin>>a[i][j];
		}
	}
	int c = 0;
	while(!b[n])
	{
		memset(u,0,sizeof(u));
		c = 0;
		for(int i=0;i<n;i++)
		{
			if(b[i])
			{
				 for(int j=1;j<=a[i][0];j++)
				 {
				 	if(!u[a[i][j]]){
				 	c++;
				 	u[a[i][j]] = 1;
				 	}
				 }
			}

		}
		if(c==m) ans++;
		b[0]++;
		for(int i=0;i<n;i++)
		{
			if(b[i]>1)
			{
				b[i] = 0;
				b[i+1]++;
			}
		}
	}
	cout<<ans;
	return 0;
}
