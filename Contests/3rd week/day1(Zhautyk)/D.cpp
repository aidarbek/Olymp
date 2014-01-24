#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int  n,m,val;
bool f;
int  a[100001];
bool u[100001];
int  q;
int  from,to;
void dfs(int v, int till)
{
	val++;
	u[v] = 1;
	if(v==till)
	{
		f = 1;
	}
	else if(a[v]!=0 && !u[a[v]])
	{
		dfs(a[v],till);
	}
}
int main()
{
	freopen("specialg.in","r",stdin);
	freopen("specialg.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=sqrt(m);i++)
	{
		cin>>q>>from;
		if(q==1) a[from] = 0;
		else
		{
			cin>>to;
			if(from!=to)
			{
				val = 0;
				f   = 0;
				memset(u,0,n+1);
				dfs(from,to);
				if(f) cout<<val-1<<endl;
				else cout<<-1<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}