#include <iostream>
using namespace std;

int  n;
int  m[1000];
int  a[1000][1000];
bool u[1000];//if 1 - NO
			 //if 0 - YES

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;
	int index;
	int mx = -9999;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		if(m[i]>mx)
		{
		 index = i;
		 mx    = m[i];
		}
		for(int j=1;j<=m[i];j++)
		{
			  cin>>a[i][j];
		}
	}
	u[index] = 1;
	for(int i=1;i<=n;i++)
	{
	    for(int j=1;j<=n;j++)
	    {
	    	int c = 0;
	     	for(int k=1;k<=m[j];k++)
	     	{
	     		 if(a[i][k]==a[j][k]) c++;
	     	}
	     	if(m[i]==m[j] && m[i]==c)
	     	{
	     	   u[i] = 1;
	     	   u[j] = 1;
	     	}
	    }
	}
	for(int i=1;i<=n;i++)
	{
	   if(!u[i]) cout<<"YES"<<endl;
	   else cout<<"NO"<<endl;
	}
	return 0;
}