#include <iostream>
using namespace std;
int a[1001][1001];
int t;
int n,m;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		memset(a,2,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j] = 2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>a[i][j];
		 bool yes = 0;
		 for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]==a[i+1][j] && a[i][j+1]==a[i][j] && a[i][j]==a[i+1][j+1])
				{
					yes = 1;
				}
			}
		if(yes) cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}