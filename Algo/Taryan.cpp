#include <iostream>
#include <vector>
using namespace std;
vector<int> g[10000];
vector<int> q[10000];
int dsu[1000];    
int ancestor[1000];
int n;
int m;
int x,y;
bool u[1000];
int dsu_get(int v)
{
	if(dsu[v]==v) return v;
	else return dsu[v] = dsu_get(dsu[v]);
}
void dsu_creat(int v)
{
	dsu[v] = v;
	ancestor[v] = v;
}
int dsu_unit(int a,int b,int new_ancestor)
{
	a = dsu_get(a);
	b = dsu_get(b);
	dsu[a] = b;
	ancestor[b] = new_ancestor;
}
void dfs(int v)
{
	dsu_creat(v);
	u[v] = 1;
	int to;
	for(int i=0;i<g[v].size();i++)	
	{
		to = g[v][i];
		if(!u[to]) 
		{
			dfs(to);
			dsu_unit(v,to,v);
		}
	}
	for(int i=0;i<q[v].size();i++)
	{          
		to = q[v][i];
		if(u[to])
			cout<<v<<"-"<<to<<"->"<<ancestor[dsu_get(to)]<<endl;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		q[x].push_back(y);
		q[y].push_back(x);
	}
	dfs(1);

	return 0;
}