#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n, p;
int s, f;
int sum;
int ps, pf; //parent string, fret
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{   
		cin>>s>>f;
		sum++;
		if(f<pf && ps==s && pf!=0 && ps!=0)
		{
			 sum++;
		}
		ps = s;
		pf = f;              
	}
	cout<<sum;
	return 0;
}

