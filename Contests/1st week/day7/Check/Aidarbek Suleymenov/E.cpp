#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
using namespace std;
int n;
vector<int> g[3000001];
int q;
int x,y;
int t;
bool cicle;
int a[300001];
int last;
void dfs(int v)
{
	a[v] = 1;
	last = v;	
	for(int i=0;i<g[v].size();i++)
	{
		if(g[v][i]!=0 && a[g[v][i]]==0)
		{
			 dfs(g[v][i]);
		}    
		else if(a[g[v][i]] == 1)
		{
			cicle = 1;       
		}
	}
	a[v] = 2;
}
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		g[i].push_back(x);
	}
	cin>>q;
	x = 0;
	for(int i=1;i<=q;i++)
	{
		cin>>t>>x;
		if(t==2)
		{
			g[x].pop_back();		
			/*----------------
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<1;j++)
					{
						cout<<g[i][j]<<" ";
					}
					cout<<endl;
				}
			----------------*/
		}
		else if(t==1)
		{
			last  = 0;
			cicle = 0;
			dfs(x);
			memset(a, 0,sizeof(a));
			
			if(cicle) cout<<"CIKLUS\n";
			else cout<<last<<endl;
		}                               	
	}
	return 0;
}   
