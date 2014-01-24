#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MAXN 10001
using namespace std;
int n;
int a[1002][1002];
int main()
{
	freopen("moose.in","r",stdin);
	freopen("moose.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i][1];
		for(int j=2;j<=a[i][1];j++)
		{ 
			cin>>a[i][j];
		}
	}
	int max1 = -9999;
	for(int i=2;i<=a[n][1];i++)
	{
	    max1 = max(a[n][i], max1);
	}
	int ans = 0;
	ans = max1;
	for(int i=n-1;i>=1;i--)
	{
		int max2 = -MAXN;
		for(int j=2;j<=a[i][1];j++)
		{
			  if(a[i][j] >max2 && a[i][j]<max1 )
			  {
			  	max2 = a[i][j];
			  }
		}          
		max1 = max2;
		if(max2 == -MAXN)
		{
			cout<<-1;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
