#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <vector>
#include <map>
#define  MAXN 20001
using namespace std;

vector<int> g[MAXN];
bool u[MAXN];
int tup[MAXN],tin[MAXN];
int n,m;
int x,y;
int timer;
vector< pair<int,int> > ans;
vector<int> f;
map<pair<int,int>, int> m1;
void dfs(int v, int p = -1)
{
    int to;
	u[v] = 1;
	timer++;
	tup[v] = timer;
	tin[v] = tup[v];
	for(int i=0;i<g[v].size();i++)
	{
		to = g[v][i];
		if(p==to) 
		{
			//tup[v] = min(tup[v],tup[p]);
			continue;
		}
		if(u[to])
		{
			tup[v] = min(tup[v], tin[to]);
		}
		else
		{
	//		cerr<<v<<" "<<to<<endl;	
			dfs(to,v);
			tup[v] = min(tup[v],tup[to]);
			if(tup[to] > tin[v])
			{
				
				if(m1[make_pair(v,to)]) 
				   f.push_back(m1[make_pair(v,to)]);                      	
				if(m1[make_pair(to,v)])
				   f.push_back(m1[make_pair(to,v)]);
				
				//ans.push_back(make_pair(v,to));		
				//ans.push_back(make_pair(to,v));
			}
		}
	}

}
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		m1[make_pair(x,y)] = i;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!u[i]) dfs(i);
	}
	//sort(ans.end(),ans.begin());
	//cerr<<ans.size();
	int t;
	
	/*for(int i=0;i<ans.size();i++)
	{
		t = m1[ans[i]];
		if(t) f.push_back(t);
	}*/
	cout<<f.size()<<endl;
	sort(f.begin(),f.end());
	for(int i=0; i < f.size() ;i++)
	{
		cout<<f[i]<<" ";
	}
	return 0;
} 