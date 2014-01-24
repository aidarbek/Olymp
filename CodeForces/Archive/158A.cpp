#include <iostream>
using namespace std;
int n,k;
int a[1001];
int c;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}                              
	for(int i=0;i<n;i++)
	{
		if(a[i]>0 && a[i]>=a[k-1])
			c++;
	}
	cout<<c;
	return 0;
}
