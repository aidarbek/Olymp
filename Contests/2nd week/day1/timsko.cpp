#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
int main()
{
	freopen("sosay.in","r",stdin);
	freopen("sosay.out","w",stdout);
	int m,n,k;
	int tms = 0;
	cin>>m>>n>>k;
	int g = m;
	for(int i=1;i<=n;i++)
	{
		 if(g>=2)
		 {
		 	g-=2;
		 	tms++;
		 }
	}
	tms*=3;
	if(n+m - tms >=k)
	{
		cout<<tms/3;
	}
	else
	{
		k-= n+m-tms;
		tms-=k;
		cout<<tms/3;
	}
	return 0;
}