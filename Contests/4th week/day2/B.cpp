#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MAXN 999999
using namespace std;
int n,a[1000];
bool u[1000];
int ans = 0;
int mn = MAXN;
int c = 0;
void go(int v)
{
	u[v] = 1;
	c++;
	int l=v-1,r=v+1;
	for(;;l--)
	{
		if(!u[l]) break;
	}
	for(;;r++)
		if(!u[r]) break;
	ans+= a[v]*(a[l]+a[r]);
	if(c==n-2)
	{
		mn = min(ans,mn);	
	}
	else
	{
		for(int i=2;i<=n-1;i++)
		{	
			if(!u[i]) go(i);
		}
	}
	u[v] = 0;
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n-1;i++)
	{
		ans = 0;
		go(i);
	}
	if(mn<MAXN) cout<<mn;
	else cout<<0;
	return 0;
} 