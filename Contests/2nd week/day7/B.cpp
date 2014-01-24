#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
int n;
int k;
int c = 0;
bool u[10010];
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>k;
	for(int i=2;i<=n;i++)
	{
		if(!u[i])
		{
			for(int j=i;j<=n;j+=i)
			{
				if(!u[j])
				{
					u[j] = 1;
					c++;
					if(c==k)
					{
						cout<<j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}