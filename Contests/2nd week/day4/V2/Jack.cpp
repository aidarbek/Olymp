#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,m;
int a[1000];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ans;
	int mn = 1999999;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(i!=j && j!=k && i!=k)
				{
					if(m-(a[i]+a[j]+a[k])>=0)
					{
						if(m-(a[i]+a[j]+a[k])<=mn)
						{
							mn  = m-(a[i]+a[j]+a[k]);
							ans = a[i]+a[j]+a[k];
						}
					}
				} 			
			}

		}
	}
	cout<<ans;
	return 0;
}
