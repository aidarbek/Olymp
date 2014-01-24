#include <iostream>
#include <queue>
using namespace std;
int a[1000][1000];
int ans = 0;
int step = 0;
int n,k;
int dfs(int v)
{
	step++;
	if(step == k && v==n)
	{
		ans++;
	}
	else if(v<=n && v>=1)
	{    
		dfs(v+1);
		if(v>1) dfs(v-1);
	}
	else if(v>n)
	{
		dfs(v-1);
	}
}
int main()
{
	freopen("input.txt", "r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n+1;i++)
	{
		a[i][i+1] = 1;
		a[i+1][i] = 1;
	}  
	dfs(1);
	cout<<ans;
	return 0;
}
