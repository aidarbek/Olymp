#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
int  a[1000][1000];
bool u[1000];
int  p[1000];
int  n,m,l;
int  s,t,c;
int  w;
vector<int> vec;
vector< vector<int> > ans;
void dfs(int v)
{
	
	//cerr<<v<<" ";
	int k = v;
	if(v==n)
	{   
		//u[v] = 0;
		vec.clear();
		while(k!=1)
		{
			vec.push_back(k);
			k = p[k];
		}             		
		vec.push_back(1);
		vec.push_back(w);
		reverse(vec.begin(),vec.end());
		ans.push_back(vec);
		for(int i=0;i<vec.size();i++)
		{
			cerr<<vec[i]<<" ";
		}
		cerr<<endl;
		//u[v] = 1;
	}
	
	else
	{ 
		for(int i=1;i<=n;i++)
		{	
			if((a[v][i]!=0 )) 
			{
				w+=a[v][i];
				p[i] = v;
				dfs(i);
				
				w-=a[v][i];
			}
		}        
	}        
}
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	cin>>n>>m>>l;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>t>>c;
		a[s][t] = c;
		//a[t][s] = c;
	}
	u[1] = 1;
	dfs(1);
	sort(ans.begin(), ans.end());
	for(int i=0;i<l;i++)
	{
			cout<<ans[i].size()-1<<" ";
			for(int j=1;j<ans[i].size();j++)
			{
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		
	}
	return 0;
}