#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n;
int p[1001];
int k[1001];
int d[1001];

int main()
{
	freopen("sosay.in","r",stdin);
	freopen("sosay.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
	}
	for(int i=1;i<=n;i++)
	{
		d[i] =  k[i] - p[i];
	}
	int ans = 0;
	int pos = 0;
	int mx =  -999999;
	int mn =  999999;
	
	while(pos!=3)
	{
		mx = -999999;
		mn =  999999;
		pos = 0;
		for(int i=1;i<=n;i++)
		{
			if(pos==0)
			{
				if(d[i]>0) {pos = 1;mx = max(mx, d[i]); d[i]=0;}
				if(d[i]<0) {pos = 2;mn = min(mn, d[i]); d[i]=0;}

			}
			else
			{
				if(pos == 1 && d[i]>0)
				{
					  mx = max(mx, d[i]);
					  d[i] = 0;
				}
				else if(pos==2 && d[i]<0)
				{
					  mn = min(mn, d[i]);
					  d[i] = 0;
				}
				else if(pos==1 && d[i]<=0 || pos==2 && d[i]>=0)
				{
					break;				
				}
			}
		}
		if(mx>0)     ans+=mx;
		else if(mn<0)ans+=mn*(-1);
		if(pos==0) pos = 3;
	}
	cout<<ans;
	return 0;
}
