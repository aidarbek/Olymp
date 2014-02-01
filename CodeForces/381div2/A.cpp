#include <iostream>
using namespace std;
int n,m,l,r;
int a[10000];
int ans1 = 0, ans2 = 0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];

	}
	l = 1,r = n;
	int step = 0;
	while(l<=r)
	{
		step++;
		if(step%2==1)
		{
			if(a[r]>a[l])
			{
				ans1+=a[r];
				r--;
			}
			else
			{
				ans1+=a[l];
				l++;
			}
		}
		else
		{
			if(a[r]>a[l])
			{
				ans2+=a[r];
				r--;
			}
			else
			{
				ans2+=a[l];
				l++;
			}
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}