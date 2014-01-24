#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int  a[1000];
bool u[1000];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n = 10;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int k = 42;
	int rem = 0;
	for(int i=1;i<=n;i++)
	{
		rem = a[i]%k;
		u[rem] = 1;
	}
	int ans = 0;
	for(int i=0;i<=50;i++)
	{
		if(u[i])
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
