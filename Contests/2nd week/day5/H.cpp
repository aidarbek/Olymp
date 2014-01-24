#include <iostream>
#include <stdio.h>
#include <cstdlib>
using  namespace std;
int a[10000];
int b[10000];
int main()
{
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
	int n;
	cin>>n;
	while(a[n]==0)
	{
		for(int i=0;i<n;i++)
		{
			b[a[i]]++;
		}
		a[0]++;
		for(int i=0;i<n;i++)
		{
			if(a[i]>9)
			{
				a[i] = 0;
				a[i+1]++;
			}
		}
	}
	for(int i=0;i<=9;i++)
	{
		cout<<b[i]*2<<" ";
	}
	return 0;
}