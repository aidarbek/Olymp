#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int n,m;
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>n>>m;
	if(m>=n) cout<<n;
	else
	{
		int steps = 0;
		while(n>m)
		{
			 n=(n-m)/2;
			 steps++;
		}
		cout<<steps*m+n;
	}
	return 0;
}

