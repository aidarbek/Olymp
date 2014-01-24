#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[10000];
	int mn = 100000;
	int mx = -100000;
	int ans = 0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			mn = a[i];
			mx = a[i];
		}
		else
		{
			if(a[i]<mn) 
			{
			 	mn = a[i];
			 	ans++;
			}
			if(a[i]>mx)
			{
				mx = a[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}