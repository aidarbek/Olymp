#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int x;
	int mn = -99999;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			mn = max(mn, x);
		}
	}
	cout<<mn<<" "<<m*n;
	return 0;
}