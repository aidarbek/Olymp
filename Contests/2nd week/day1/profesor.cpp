#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
using namespace std;
pair<int,int> p[100000];
pair<int,int> ans;
int marks[6];
int main()
{
	freopen("sosay.in","r",stdin);
	freopen("sosay.out","w",stdout);
	int n;
	cin>>n;
	int x,y,x1,y1;
	marks[1] = 1;
	marks[2] = 1;
	marks[3] = 1;
	marks[4] = 1;
	marks[5] = 1;
	int m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		if(i==1 && p[i].first==p[i].second) marks[p[i].second]=2;  			
			x  = p[i].first;
			y  = p[i].second;
			x1 = p[i-1].first;
			y1 = p[i-1].second;
			if(x==x1 || x==y1 || y==x1 || y==y1)
			{
				 if(x==y && x==x1 && x==y1)
				 {        
				 	marks[x]+=2;
				 }
				 else
				 {
					 if(x==x1) marks[x]++;
					 if(x==y1) marks[x]++;
					 if(y==x1) marks[y]++;
					 if(y==y1) marks[y]++;
				 }
			}
			else if(i>1)
			{
				marks[x]  = 1;
				marks[y]  = 1;
				marks[x1] = 1;
				marks[y1] = 1;			
			}
			m = 5;
			if(ans.first <= marks[m])
			{
				ans.first  = marks[m];
				ans.second = m;
			}
			m = 4;
			if(ans.first <= marks[m])
			{
				ans.first  = marks[m];
				ans.second = m;
			}
			m = 3;
			if(ans.first <= marks[m])
			{
				ans.first  = marks[m];
				ans.second = m;
			}
			m = 2;
			if(ans.first <= marks[m])
			{
				ans.first  = marks[m];
				ans.second = m;
			}
			m = 1;
			if(ans.first <= marks[m])
			{
				ans.first  = marks[m];
				ans.second = m;
			}
	}
	cout<<ans.first<<" "<<ans.second;
	return 0;
}
