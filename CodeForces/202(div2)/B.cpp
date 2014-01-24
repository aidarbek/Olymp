#include <iostream>
#include <algorithm>
using namespace std;
int v;
int a[10];
int u[10];
pair<int, int> p[10];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>v;
	int n=9;
	for(int i=1;i<=n;i++)
	{
		 cin>>a[i];
		 p[i].first = a[i];
		 p[i].second = i;
	}
	sort(p,p+n);
	int l = 0;
	for(int i=1;i<=n;i++)
	{
		  l = 0;
		  int d[10];
		  for(int j=i;j<=n;j++)
		  {
		  		if(p[i].first==p[j].first)  
		  		{
		  			d[l] = p[j].second;
		  			l++;
		  		}
		  }
		  
		  if(l>0)
		  {
			  sort(d,d+l);
			  for(int j=0;j<l;j++) cout<<d[j]<<" ";
			  cout<<endl;
			  int k = l;
			  for(int j=i;j<i+k;j++)
			  {
			  		l--;
			  		p[j].second = d[l];
		  	  }
		  }
	}
	for(int i=1;i<=n;i++)
	{                                            
		
	}
	return 0;
}
