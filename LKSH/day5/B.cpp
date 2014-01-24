#include <iostream>
using namespace std;
int a[1001][1001];
int n,m;
int s1[1001];
int s2[1001];
int s3[1001];
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s2[i];
	}
	if(m>n)
	{
		for(int i=1;i<=m;i++)
		{
			s3[i] = s1[i];
		}
		for(int i=1;i<=m;i++)
		{
			s1[i] = s2[i];
		}
		for(int i=1;i<=m;i++)
		{
			s2[i] = s3[i];
		}
		swap(m,n);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s1[i]!=s2[j])
			{
				a[i][j] = max(a[i-1][j], a[i][j-1]);
			}
			else
			{
				a[i][j] = a[i][j-1]+1;
			}
		}          
	}
	cout<<a[n][m];
	return 0;
}
