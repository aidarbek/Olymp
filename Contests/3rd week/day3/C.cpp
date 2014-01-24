#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define INF 10000000
using namespace std;
int n;
int a[1001];
int m;
int main()
{
	freopen("in","r",stdin);		
	freopen("out","w",stdout);
	a[0] = -INF;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		m = a[i];
		for(int j=i-1;j>=1;j--)
		{
			if(j>0)
			{
				if(m<=a[j])
				{
					sum+=a[j]-m+1;
					m--;
					a[j] = m;
				}
				else
				{
					m = a[j];
				}
			}
		}
	}
	cout<<sum;
	return 0;
}	
