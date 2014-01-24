#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
bool u[100000];
int t = 0;
int n;
int a[100000];
bool yes = 0;
int main()
{
	freopen("glade.in","r",stdin);
	freopen("glade.out","w",stdout);
	cin>>t;       
	for(int p=1;p<=t;p++)
	{
		cin>>n;      
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		yes = 0;
		int max1 = 0;
		for(int i=1;i<=n;i++)
		{
			memset(u,0,sizeof(u));
			int same = 0;
			for(int j=1;j<=n;j++)
			{
				if(a[j]==a[j+i] && j+i<=n)
				{
					u[j]   = 1;
					u[j+i] = 1;
					same+=2;				
				}
			}
			if(same>=n-1)
			{
				max1 = max(max1, same);
				yes = 1;
				break;
			}
				max1 = max(max1, same);
		}               
		if(yes) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
