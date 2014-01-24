#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <utility>
using namespace std;
int n,m,k;
pair<double,int> p[10001];
bool u[10001];
int main()
{
	freopen("cocai.in","r",stdin);
	freopen("cocai.out","w",stdout);
	cin>>n>>m>>k;
	double y;
	int x;
	int c = 0;
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>x>>y;
			p[c].first  = y;
			p[c].second = x;
			c++;
		}
	}
	sort(p,p+c);
	double sum = 0.0;
	int t = 0;
	for(int i=c-1;i>=0;i--)
	{
		int    y1 = p[i].second;
		double x1 = p[i].first;
		if(!u[y1])
		{
			u[y1] = 1;
			sum+=x1;
			t++;
		}                       
		if(t==k) break;
	}                   
	printf("%.1f", sum);
	return 0;
}
