#include <iostream>
#include <string.h>
using namespace std;
int n,a[1001];
int d[1001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) d[i] = 1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=1;j--)
		{
			if(a[i]%a[j]==0 && i!=j)
			{
				d[i] = max(d[i], d[j]+1);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<d[i]<<" ";
	}
	return 0;
}
