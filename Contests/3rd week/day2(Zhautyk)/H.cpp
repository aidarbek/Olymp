#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n,m,l,r,x,a[300001];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>l>>r>>x;
		for(int j=l;j<=r;j++)
		{
			a[j] = max(a[j],x+j-l);
		}
	}		
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}