#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int n,r;
	int x,y;
	int not_from_r = 0, from_r = 0;
	int c =0;
	cin>>n>>r;
	for(int i=1;i<=n-1;i++)
	{
		cin>>x>>y;
		if(x!=r && y!=r && not_from_r==0)
		{
			not_from_r = i;	
		}
		if(x==r || y==r)
		{
			c++;
			if(from_r==0) from_r = i;
		}
	}
	if(c%2==0 && not_from_r==0)
	{
		cout<<"2";
	}
	else 
	{
		cout<<"1"<<endl;
		if(c%2==1) cout<<from_r;
		else cout<<not_from_r;
	}      	
	return 0;
} 