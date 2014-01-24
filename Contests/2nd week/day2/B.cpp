#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
int a[100001];
		
int main()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	int k,n,x;
	cin>>k;
	for(int i=1;i<=k;i++)
	{                                 
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			a[x]++;
			a[i]++;		
		}
		int mx=-99999;
		for(int i=1;i<=n;i++)
		{
			  mx = max(mx, a[i]);
		}
        cout<<mx<<endl;
    }
	return 0;
}
