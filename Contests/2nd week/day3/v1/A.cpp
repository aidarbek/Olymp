#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
#define MINN -99999
using namespace std;
int  n;
int  a[1000];
int  b[1000];
int  c[1000];
bool u1[1000];
bool u2[1000];
int  k=1;
int  m=1;
int  mx = MINN;
int  index;      
int main()
{	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	while(cin>>a[k])
	{
		k++;
	}
	n=k/2;
	for(int i=1;i<=n;i++)
	{
		b[i] = a[i];
	}
	for(int i=n+1;i<=k;i++)
	{
		c[m] = a[i];
		m++;
	}
	sort(b+1,b+1+n);
	int ans = 0;
	for(int i=1;i<=n;i++)
	{
		mx = MINN;
		index = 0;
		for(int j=1;j<=n;j++)
		{
			if(c[j]>mx && c[j]<b[i] && !u1[i] && !u2[j])
			{
				mx = c[j];
				index = j;
			}
		}
		if(index)
		{
			u2[index] = 1;
			ans+=2;
			u1[i] = 1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!u1[i] && !u2[j] && b[i]==c[j])
			{
				u1[i] = 1;
				u2[j] = 1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
