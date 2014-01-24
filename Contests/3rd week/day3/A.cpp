#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("in","r",stdin);		
	freopen("out","w",stdout);
	int lj,p;
	int n=5;
	int a[10];
	cin>>lj>>p;
	int m = lj*p;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cout<<a[i]-m<<" ";
	}
	return 0;
}	
