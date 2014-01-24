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
	

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	
	for(int i=0;i<=n;i++) d[i] = INF;
	
	d[1] = 0;
	
	for(int i=0;i<m;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].w;
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(d[e[j].a]<INF)
			{
				d[e[j].b] = min(d[e[j].b], e[j].w+d[e[j].a]);
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<d[i]<<" ";
	return 0;
}   	