#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;
int price(int x,int y, int z,int n,int m)
{
	return (ceil(double(m)/double(z))*n)*x+(m*n)*y;
}
int main()
{
	freopen("E.in","r",stdin);
	freopen("E.out","w",stdout);
	int a,b,c,d,e,f,n,m;
	cin>>a>>b>>c>>d>>e>>f>>n>>m;
	int p1 = price(a,b,c,n,m);
	int p2 = price(d,e,f,n,m);
	if(p2<=p1)
	{
		cout<<p2<<" " <<0<<" "<<ceil(m/f)*n;	
	}	
	else
	{
		cout<<0<<" " <<p1<<" "<<ceil(m/c)*n;	
	}
	return 0;
}