#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int a[1100];
int n;
int main()
{
	freopen("rozetka.in","r",stdin);
	freopen("rozetka.out","w",stdout);
	cin>>n;
	a[1] = 3; 
	for(int i=2;i<=n;i++)
	{
		a[i]+=a[i-1];  
		for(int j=0;j<=i;j++)
		{
			a[i]+=j+i;
		}
	}
	cout<<a[n];
	return 0;
}