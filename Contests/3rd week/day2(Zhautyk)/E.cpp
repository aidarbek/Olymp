#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int t,n,p[10001];
int m,c;
int k;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		memset(p,0,sizeof(p));
		for(int j=1;j<=n;j++)
		{
			cin>>p[j];
		}
		m = n;
		c = 0;
		while(p[m]==m)
		{
			c++;
			m--;
		}
		if(c==0) 
		{
				cout<<0<<endl;     		
		}
		else
		{
			if(n-c>0) cout<<p[n-c]<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}