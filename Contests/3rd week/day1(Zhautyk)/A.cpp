#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
using namespace std;
double abs1(double val)
{
	if(val<0) val*=-1;
	return val;
}
int main()
{
	freopen("expgorl.in","r",stdin);
	freopen("expgorl.out","w",stdout);
	double mn=999999,mx=-999999;
	double x1,x2,y1,y2;
	double l;
	string s;
	int k;
	cin>>k;
	cin>>s;
	cin>>x1>>y1>>x2>>y2;
	int m;
	m = s.size();
	l = sqrt(pow(abs1(x1-x2),2) + pow(abs1(y1-y2),2));
	mx = max(mx,l);
	mn = min(mn,l);
	for(int i=1;i<=k;i++)
	{
	      for(int j=0;j<m;j++)
	      {
	      		if(s[j]=='L')
	      		{
	      			x2--;
	      		}
	      		else if(s[j]=='R')
	      		{
	      			x2++;	      		
	      		}
	      		else if(s[j]=='F')
	      		{
	      			y2++;	      		
	      		}
	      		else if(s[j]=='B')
	      		{
	      			y2--;	      		
	      		}
	      		l = sqrt(pow(abs1(x1-x2),2) + pow(abs1(y1-y2),2));
	      		mx = max(mx,l);
	      		mn = min(mn,l);
	      }
	}
	printf("%.9f %.9f", mn,mx);
	return 0;
}