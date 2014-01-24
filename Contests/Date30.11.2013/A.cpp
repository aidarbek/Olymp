#include <iostream>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;
int    n;
int    a[10001];
int    d[10001];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int mul = 1;
		int x   = a[i];
		while(x>9)
		{
			  int v = x%10;		
			  mul  *= v;
			  x /= 10;
		}
		mul*=x;
		d[i] = mul;
	}
	int mn = 10000;
	int x,y;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				 int val = d[i]-d[j];
				 if(val<0) val *= -1;
				 if(val<mn)
				 {
				 	mn = val;
				 	
				 	if(a[i]<a[j])
				 	{
				 		x  = i;
				 		y  = j;
				 	}
				 	else
				 	{
				 		x = j;
				 		y = i;
				 	}
				 }
				 else if(val==mn)
				 {
				 	if(a[i]<a[x])
				 	{
				 		x = i;
				 		y = j;
				 	}
				 	else if(a[i]==a[x])
				 	{
				 		if(a[j]<a[y])
				 		{
				 			y = j;
				 		}
				 	}
				 }
			}
		}
	}
	cout<<a[x]<<" "<<a[y];	
	return 0;
}
