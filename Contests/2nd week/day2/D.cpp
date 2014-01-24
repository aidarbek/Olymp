#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int a[1001][1001];
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	int sum = 0;             
	for(int i=1;i<=n;i++)
	{	
		sum+=a[i][i];
	}
	cout<<sum;
	return 0;
}
