#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define ll long long
using namespace std;
ll a,b,c,l,r,p;
ll f(int x)
{
	return ((x-a)*(x-b)*(x-c))%p;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	//A, B, C, L, R, P
	ll sum = 0;
	cin>>a>>b>>c>>l>>r>>p;
	for(int i=l;i<=r;i++)
	{
		//cout<<f(i)<<endl;
		sum+=f(i);
	}
	cout<<sum%p;
	return 0;
}