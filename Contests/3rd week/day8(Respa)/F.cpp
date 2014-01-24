#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <utility>
using namespace std;
int  n,m;
int  q;
char c;
vector< pair<int,int> > g[10000];//Vertex, Canditate
int x,y;
pair<int,int> streets[100000];
int k;
void change(int v1, int v2, int val)
{
	for(int i=0;i<g[v1].size();i++)
	{
		if(v2==g[v1][i].first)
		{
			g[v1][i].second = val;
		}
	}
}
int  way[10000];
bool   u[10000];
void dfs(int v, int to)
{
	u[v] = 1;
	for(int i=0;i<g[v].size();i++)
	{
		way[i] = v;
		if(g[v][i].first == to)
		{
			way[i] = v;
		}
		else
		{
			dfs(g[v][i].first, to);		
		}
	}		
}
int cnt(int v, int what)
{
	int res = 0;
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i].second==what)
		{
			res++;
		}
	}
	return res;
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		streets[i].first = x;
		streets[i].second = y;
		g[x].push_back(make_pair(y,1));
		g[y].push_back(make_pair(x,1));
	}
	int sum = 0;
	cin>>q;
	int key;
	for(int i=1;i<=q;i++)
	{
		cin>>c>>x>>y;
		if(c=='+')
		{
			change(streets[x].first, streets[x].second, y);
			change(streets[x].second, streets[x].first, y);		
		}
		else
		{
			cin>>k;
			sum = 0;
			memset(way,0, sizeof(way));
			memset(u,0, sizeof(u));		
			dfs(x,y);
			key = y;
			while(way[key]!=x)
			{
				sum+=cnt(key, k);
				key = way[key];
			}
			sum+=cnt(key, k);
			cout<<key<<endl;
		}
	}
	return 0;
}