#include <iostream>
#include <map>
#include <algorithm>
#define MAXN 1000001
using namespace std;
int n,m;
int a[10000];
int b[10000];
bool u[10000];
int mn;
int ans;         
int index;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	ans = n;
	for(int i=0;i<m;i++)
	{
		cin>>b[i];          	
	}
	//sort(a,a+n);
	for(int i=0;i<m;i++)
	{
		mn = MAXN;
		index = -1;
		for(int j=0;j<n;j++)
		{
			if(!u[j])
			{
				if(b[i]-a[j]>=0)
				{
					if(b[i]-a[j]<mn)
					{
						mn = b[i]-a[j];
						index = j;
					}
				}
			}	
		}
		if(index!=-1)
		{
		 	u[index] = 1;
		 	ans--;
		}
	}
	cout<<ans;
	return 0;
}