#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define MAXN 10001
using namespace std;
int  n,m,k;
int  t[MAXN];
int  f[MAXN];
int  a[MAXN];
bool u[MAXN];
int main()
{
	freopen("knifenfork.in","r",stdin);
	freopen("knifenfork.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		   cin>>t[i]>>f[i]>>a[i];
		   f[i]+=t[i];
		   bool ordered = 0;		   
		   
		   for(int j=1;j<=i;j++)
		   {
		   		if(!ordered)
		   		{
		   			if(t[i]>=f[j] || i==j)
		   			{
		   				if(a[j]==0 && i!=j)
		   				{
		   					n++;
		   				}
		   				if(a[j]==1 && i!=j)
		   				{
		   					n++;
		   					m++;
		   				}
		   				if(a[i]==0 && n>0) 
		   				{
		   					n--;
		   					ordered = 1;
		   				}
		   				if(a[i]==1 && n>0 && m>0)
		   				{
		   					n--;
		   					m--;
		   					ordered = 1;
		   				}
		   			}
		   		}
		   		else break;      
		   }
		   if(ordered) cout<<"Yes\n";
		   else cout<<"No\n";
	}               
	return 0;
}
