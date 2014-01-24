#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MOD 1000000007
using namespace std;
int  a[20001];
int  n;
bool u[20001];
int  f[20001] ;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	f[0] = 1;
	for(int i=1;i<=n;i++)
	{
		f[i] = (f[i-1]*i) % MOD;
	}
	int num   = 0;
	int order = 0;
	u[a[1]] = 1;
	num+=((a[1]-1)*f[n-1]) %MOD;	
	for(int i=2;i<=n-1;i++)
	{   
		order=0;
		if(i==n-1)
		{
			for(int j=1;j<=a[i];j++)
			{
				if(!u[j]) order++;
			}
			num+=order%MOD;
		}
		else
		{
			for(int j=1;j<=a[i];j++)
			{
				if(!u[j]) order++;
			}
			u[a[i]] = 1;
			num+=((order-1)*(f[n-i]))%MOD;
		}
	}
	cout<<num;
	return 0;
}
