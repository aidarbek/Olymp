/*
ID: suleyme1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	string a,b;
	int a1 = 1, b1 = 1;
	cin>>a>>b;
	for(int i=0;i<a.size();i++)
	{
		 a1 *= a[i]-'A'+1;
	}

	for(int i=0;i<b.size();i++)
	{
		 b1 *= b[i]-'A'+1;
	}
	if(a1%47 == b1%47) cout<<"GO";
	else cout<<"STAY";
	cout<<endl;
	return 0;
}
