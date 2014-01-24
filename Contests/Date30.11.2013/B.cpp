#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;
int n;
pair<pair<int,int>, pair<int,int> > p[1000];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	cin>>n;
	int x,y,z,w;
	int a[10];
	for(int i=1;i<=n;i++)
	{
		w = 0;
		cin>>x>>y>>z;
		a[0] = x;
		a[1] = y;
		a[2] = z;
		sort(a,a+2);
		if(a[0]!=a[1]) w = 1;
		p[i].first.first   = x; 
		p[i].first.second  = y;
		p[i].second.first  = z;
		p[i].second.second = w;
	}
	sort(p, p+n);
	int x1,y1,z1;
	int x2,y2,z2;
	int f1=0,f2=0,f3=0;
	bool is3 = 0;
	for(int i=1;i<=n;i++)
	{
		int n2 = 0;
		int n3 = 0;
		int f = 0;
		int s = 0;
		  for(int j=1;j<=n;j++)
		  {
		  	  if(i!=j)
		  	  { 	
		  	  	    if(!p[i].second.second && !p[j].second.second )
		  	  	    {
						x1 = p[i].first.first; 
						y1 = p[i].first.second;
						z1 = p[i].second.first;
						
						x2 = p[j].first.first; 
						y2 = p[j].first.second;
						z2 = p[j].second.first;
						if(x1==x2 && y1==y2 && z1==z2)
						{
							n2++;
							f = j;
						}
						else
						{
							if((sqrt(x1) + sqrt(x1)) == sqrt(z2) && n2 )
							{
								n3++;
								s = j;
							}
						}
		  	  	    }
		  	  }
		  }
		  if(n2 && n3)
		  {
		  	is3 = 1;
		  	f1 = i;
		  	f2 = s;
		  	f3 = f;
		  }
		  else if(n2)
		  {
		  	 is3 = 0;
		  	 f1 = i;
		  	 f2 = s;
		  }
	}
	int ans[10];
	int m;
	if(!f1) {cout<<"Impossible";return 0;}
	if(is3) 
	{     
		m = 3;
		ans[0] = f1;
		ans[1] = f2;
		ans[2] = f3;
	}
	else 
	{
		m = 2;
		ans[0] = f1;
		ans[1] = f2;
	}
	sort(ans,ans+m);
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}
