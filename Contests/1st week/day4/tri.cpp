#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("cocni.in","r",stdin);
	freopen("cocni.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b && b==c)
	{
		cout<<a<<"="<<b<<"="<<c;
		return 0;
	}
	if(a+b==c)
	{cout<<a<<"+"<<b<<"="<<c;return 0;}
	
	if(a*b==c)
	{cout<<a<<"*"<<b<<"="<<c;return 0;}
	
	if(a-b==c)
	{cout<<a<<"-"<<b<<"="<<c;return 0;}
	
	if(a/b==c)
	{cout<<a<<"/"<<b<<"="<<c;return 0;}	
	if(c+b==a)
	{cout<<a<<"="<<b<<"+"<<c;return 0;}
	
	if(b-c==a)
	{cout<<a<<"="<<b<<"-"<<c;return 0;}
	
	if(b*c==a)
	{cout<<a<<"="<<b<<"*"<<c;return 0;}

	if(b/c==a)
	{cout<<a<<"="<<b<<"/"<<c;return 0;}
	          


	return 0;
}
