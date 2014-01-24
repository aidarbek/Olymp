#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int a[100];
int b[100];
int main()
{
	freopen("rozetka.in","r",stdin);
	freopen("rozetka.out","w",stdout);
	int n=8;
	
	for(int i=0;i<n;i++) {cin>>a[i];b[i]=a[i];}
	sort(b,b+n);
	int c=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]==a[i]) c++;
	}
	if(c==n) cout<<"ascending";
	else
	{
		c=0;
		int j=0;
		for(int i=n-1;i>=0;i--)
		{			
			if(b[i]==a[j]) c++;
			j++;
		}
		if(c==n)
			cout<<"descending";
	    else cout<<"mixed";
	}
	return 0;
}