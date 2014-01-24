#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define INF 10000000
using namespace std;
int n,q;
int a[1001];
int m;
int mx;
int c = 0;
int x;
int main()
{
	freopen("in","r",stdin);		
	freopen("out","w",stdout);
	cin>>n>>q;
	for(int k=1;k<=q;k++)
	{
		cin>>x;
		if(a[x]==1) a[x] = 0;
		else a[x] = 1;
		mx = -INF;
		c = 1;
		a[0] = a[1];
		for(int i=1;i<=n;i++)
		{
			if(a[i]!=a[i-1])
			{
				c++;
			}
			else
			{
				mx = max(mx, c);
				c = 1;
			}
		}
		mx = max(mx, c);
		cout<<mx<<endl;
	}
	return 0;
}	
