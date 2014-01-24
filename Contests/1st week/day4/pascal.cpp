#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;
int main()
{	
	freopen("cocni.in","r",stdin);
	freopen("cocni.out","w",stdout);
	long long int n;
	cin>>n;
	bool prime = 1;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0) {prime = 0 ;break;}
	}
	if(prime) cout<<n-1;
	else
	{
		int ans = 0;
		for(int i=n-1;i>=1;i--)
		{
			if(n%i==0) {ans = i; break;}
		}
		cout<<n-ans;
	}
	return 0;
}
