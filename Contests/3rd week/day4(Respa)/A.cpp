#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	double a,b;
	cin>>a>>b;
	int x = a,y = b;
	if(y %x==0)
	{
		double c = (a/b);
		printf("%.2f", c);
	}
	else
	{	
		double c =  (a/b*2);
		printf("%.2f",c);
		//printf("%.1f", sum);
	}
	return 0;
}