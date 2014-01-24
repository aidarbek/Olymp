#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int k;
	cin>>k;
	cout<<k/2<<endl;
	for(int i=1;i<=k/2;i++)
	{
		for(int i=1;i<=4;i++) cout<<0<<" ";
		cout<<endl;
	}
	return 0;
}
