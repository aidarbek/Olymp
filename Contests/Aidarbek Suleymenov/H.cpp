#include <iostream>
#include <stdlib.h>
#include <cstdio>
using namespace std;
int main()
{
	freopen("H.in","r",stdin);
	freopen("H.out","w",stdout);
	double d;

	cin>>d;
	for(double i=0.000;i<=d;i+=0.001)
	{
		if( int(((i*i*i)+(17*i*i)-7*i)) ==int(d))
		{
			cout<<i;
			if(i/1==0) cout<<".000";     
			cout<<endl;		
			break;
		}
	}
	return 0;
}
