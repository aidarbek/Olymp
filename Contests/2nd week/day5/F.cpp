#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MOD 1000000007
using namespace std;
int n;
int a[200001],b[200001];
int my_abs(int v)
{
	if(v<0) v*=-1;
	return v;
}
int main()
{
	freopen("F.in","r",stdin);
	freopen("F.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sum+=(my_abs(a[i]-a[j])+my_abs(b[i]-b[j]))%MOD;
		}
	}
	cout<<sum;
	return 0;
}