#include <iostream>
using namespace std;
int n,s,a[1001][1001];
bool u[1001];
int ans;
void dfs(int v)
{
	u[v] = 1;
	ans++;
	for(int i=1;i<=n;i++)
	{
		if(a[v][i]==1 && !u[i]) dfs(i);
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	dfs(s);
	cout<<ans-1;
	return 0;
}