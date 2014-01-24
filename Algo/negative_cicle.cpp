#include <iostream>
#include <vector>
#include <string.h>
#include <string>
#define INF 30000
using namespace std;
struct edge
{
	int a,b,w;
};
int n,m;
edge e[10001];
int d[10000];
int a[1000][1000];	

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			if(a[i][j]!=0)
			{
				e[m].a = i;
				e[m].b = j;
				e[m].w = a[i][j];				
				m++;
			}
		}
	}
	for(int i=0;i<=n;i++) d[i] = INF;
	
	d[1] = 0;
	
	int x;
	for(int i=0;i<n;i++)
	{
		x = -1;
		for(int j=0;j<m;j++)
		{
			if(d[e[j].a]<INF)
			{
				if(d[e[j].b] >e[j].w+d[e[j].a]);
				{
					d[e[j].b] = e[j].w+d[e[j].a];
					x = e[j].b;
				}
			}
		}
	}
	if(x==-1) cout<<"NO";
	else cout<<"YES";
	return 0;
}   	