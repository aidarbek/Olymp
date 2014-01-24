#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int n;
int a[10000];
int l,r;
int mx = -99999;
int j;
int main()
{
	freopen("in","r",stdin);		
	freopen("out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=n;i++)
	{
		l =i;
		r = i;
		j = i+1;
		while(a[r]<a[j])
		{
			r = j;
			j++;
		}
		mx = max(a[r]-a[l], mx);
	}
	cout<<mx;
	return 0;
}	
