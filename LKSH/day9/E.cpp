#include <iostream>
#include <vector>
using namespace std;
int  n,m;
int  a[10000][10000];
int  u[10000];
bool cicle;
vector<int> ans;
void dfs(int v)
{
	u[v] = 1;
	for(int i=1;i<=n;i++)
	{
		if(a[i][v])
		{
			if(u[i]==1)
			{
				cicle = 1;
			}
			else if(!u[i])
			{
				dfs(i);
			}
		}
	}
	u[v] = 2;   
	if(!cicle) ans.push_back(v);
}
int main()
{
	freopen("input.txt", "r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		a[x][y] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		if(u[i]==0)
		{
			dfs(i);
		}
	}
	if(cicle) {cout<<-1;return 0;}
	reverse(ans.begin(), ans.end());
	for(int i=0;i < ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
