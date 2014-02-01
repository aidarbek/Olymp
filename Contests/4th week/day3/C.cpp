#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <string>
#define T "msquare"
using namespace std;
int d[100][100];
int ans = 0;
int  n,m;     
void go(int step)
{
	bool no = 0;
	int  a[100];
	memset(a,0,sizeof(a));
	while(a[n]==0)
	{
		for(int i=0;i<n;i++) {d[step][i+1] = a[i];}
		if(step!=1)
		{
			no = 0;
			for(int i=2;i<=n;i++)
			{
				if(d[step][i]==d[step][i-1] && d[step-1][i]==d[step-1][i-1] && d[step-1][i]==d[step][i])
				{
					no = 1;
					break;
				}
			}	
			if(!no && step<m) go(step+1);
			else if(!no && step==m) 
			{
				ans++;			
			}
		}
		else if(step==1)
		{
			go(step+1);
		}
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
}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n>>m;
	go(1);
	cout<<ans;
	return 0;
}