#include <iostream>
using namespace std;
int  n, m;
int  a[10000][10000];
int  u[10000];
bool checker;
void dfs(int v)
{
	u[v] = 1;
	for(int i=1;i<=n;i++)
	{
		if(a[v][i])
		{
			if(u[i]==1)
			{
				checker = 1;
			}
			else
			{
				dfs(i);
			}
		}
	}
	u[v] = 2;
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!u[i])
		{
			dfs(i);
		}
	}
	if(checker) cout<<"There is a cicle";
	else cout<<"No cicle";
	return 0;
}