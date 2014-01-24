#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>             
using namespace std;
long long s[100],b[100];
int a[100];
long long sum;
long long mul;
long long ans = 599999999;
long long my_abs(long long x)
{
	if(x<0) x*=-1;
	return x;
}

int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n;
	cin>>n;                	
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>b[i];
	}
	int c;
	while(a[n]==0)
	{
		sum = 0;
		mul = 1;
		c = 0;
		for(int i=0;i<n;i++)
		{
			if(a[i]==1)
			{
				sum = sum + b[i];
				mul = mul * s[i];
				c++;
			}
			//cerr<<sum<<" "<<mul<<endl;
		}
		//cout<<endl;
		if(c>0) ans = min(ans, my_abs(sum-mul));
		
		a[0]++;
		for(int i=0;i<n;i++)
		{
			if(a[i]>1)
			{
				a[i] = 0;
				a[i+1]++;
			}
		}
	}
	if(ans<0)cout<<1;
	else cout<<ans;           
	return 0;
}