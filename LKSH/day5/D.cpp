#include <iostream>
using namespace std;
int  n;
int  a[100001];
bool u[100001];
int  sum;
int main()
{
	///freopen("input.txt","r",stdin);
	///freopen("output.txt","w",stdout);
	cin>>n;
	u[0] = 1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		u[a[i]] = 1;
		sum = 0;
		for(int j=a[i]-1;j>=0;j--)
		{
			if(u[j]==1) sum=j;
			u[sum+a[i]] = 1;
		}
	}
	int ans;
	for(int i=n;i>=0;i--) 
	{
		if(u[i])
		{
			ans = i;
			break;
		}
	}
	cout<<ans;   
	return 0;
}
