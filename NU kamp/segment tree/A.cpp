#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define B 65536     //2^16
#define C 1073741824//2^30
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
int d[1000001];

int n,x,y;
int m,z,t;
int main()
{
	freopen("sum0.in","r",stdin);
	freopen("sum0.out","w",stdout);
	cin>>n>>x>>y>>a[0];
	d[0] = a[0];
	for(int i=1;i<=n;i++) {a[i]=(x*a[i-1]+y) % B; d[i] = a[i]+d[i-1];}

	cin>>m>>z>>t>>b[0];
	c[0] = b[0]%n;
	for(int i=1;i<m;i++)
	{
		b[i] = (z*b[i-1]+t)%C;
		c[i] = b[i]%n;
	}
	int mn;
	int mx;
	int l,r;
	int sum = 0;
	for(int i=0;i<m;i++)
	{
		 l = c[i*2];
		 r = c[i*2+1];
		 
		 mn = min(l,r);
		 mx = max(l,r);
		
		 if(mn==0)
		 	sum+=d[mx];
		 else
		 	sum+=d[mx]-d[mn-1];
	}
	cout<<sum;
	return 0;
}
