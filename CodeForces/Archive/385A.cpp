#include <iostream>

using namespace std;
int n,c,a[1000];
int ans;
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i-1]-c>a[i])
		{
			ans = max(ans, a[i-1]-c-a[i]);
		}
	}
	cout<<ans;
	return 0;
}