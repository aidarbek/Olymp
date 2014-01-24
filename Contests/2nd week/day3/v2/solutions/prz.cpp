#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n;
int x,y;
pair<int, int> p[50001];
int main()
{
	freopen("prz.in","r",stdin);
	freopen("prz.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p[i].first>>p[i].second;
	}
	sort(p,p+n);
	x = p[0].first;
	y = p[0].second;
	for(int i=1;i<n;i++)
	{
		if(p[i].first<=y) y=max(y, p[i].second);
		else
		{
			cout<<x<<" "<<y<<endl;
			x = p[i].first;
			y = p[i].second;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}