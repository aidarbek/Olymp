#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <vector>
using namespace std;
int a[100001];
int main()
{               
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int n;
	string s;
	
	cin>>n;

	cin>>s;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='<')
		{
			a[i+2]++;
		}
		else
		{
			a[i+1]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='>')
		{
			a[i]+=a[i+1];
		}
		if(i>1)
		{
			if(s[i-2]=='<')
			{
				a[i]+=a[i-1];
			}
		}
		//cout<<a[i]<<" ";
	}
	for(int i=n;i>=1;i--)
	{
		if(s[i-1]=='>')
		{
			a[i]+=a[i+1];
		}
		if(i>1)
		{
			if(s[i-2]=='<')
			{
				a[i]+=a[i-1];
			}
		}
		//cout<<a[i]<<" ";
	}



	//cout<<endl;
	vector<int> v[100001];
	for(int i=1;i<=n;i++)
	{
		v[a[i]].push_back(i);	
	}
	int l = 1;
	int ans[100001];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			ans[v[i][j]] = l;
			l++;		
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}