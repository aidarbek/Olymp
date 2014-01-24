#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;
int n,q;
int a[100001];
int val;
int sum = 0;
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t, a1,b1,x1;//Type of the query, param1,param2,param3
	for(int i=1;i<=q;i++)
	{
		cin>>t;
		if(t==1 || t==2)
		{
			cin>>a1>>b1>>x1;		
		}
		if(t==3 || t==4)
		{
			cin>>a1>>b1;		
		}
		if(t==1)
		{
			for(int i=a1;i<=b1;i++) a[i] = x1;
		}
		if(t==2)
		{
			val = 1;
			for(int i=a1;i<=b1;i++)
			{
				a[i] +=val*x1;
				val++;
			}
		}
		if(t==4)
		{
			sum = 0;
			for(int i=a1;i<=b1;i++) sum+=a[i];
			cout<<sum<<endl;
		}
		if(t==3)
		{
			for(int i=n;i>=a1;i--)
			{
				a[i+1] = a[i];
			}
			a[a1] = b1;
			n++;
		}
	}

	return 0;
}