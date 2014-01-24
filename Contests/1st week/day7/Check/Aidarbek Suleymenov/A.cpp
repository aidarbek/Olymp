#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <algorithm>
#define MAXN 100000
using namespace std;
int  n;      
int ans = MAXN;
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	cin>>n;  
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j*3+i*5==n)
			{
				ans=min(ans,i+j);
			}
		}                      	
	}
	if(ans!=MAXN) cout<<ans;
	else cout<<-1;
	return 0;
}

