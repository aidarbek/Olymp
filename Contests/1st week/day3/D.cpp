#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int  r,c;
char a[1001][1001];
bool u[1001][1001];
int main()
{
	freopen("cocai.in","r",stdin);
	freopen("cocai.out","w",stdout);
	cin>>r>>c;
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cin>>a[i][j];
		}
	}
	bool shrt = 1;
	for(int i=1;i<=c;i++)
	{
		if(!u[r][i])
		{
			for(int j=i+1;j<=c;j++)
			{
				if(a[r][i]==a[r][j])
				{
					shrt = 0;
					u[r][i] = 1;
					u[r][j] = 1;
				}
			}
		}
	}
	int ans = 0;
	if(shrt) {cout<<r-1;return 0;}
	else
	{
		for(int i=r-1;i>=1;i--) 
		{       
			 int v = 0;
			 for(int j=1;j<=c;j++)
			 {
			 	if(a[i][j] == a[i+1][j] && u[i+1][j])
			 	{
			 		u[i][j] = 1;
			 		
			 		v++;
			 	}
			 }
			 if(v<=1)
			 {
			 	ans = (i-1);
			 	break;
			 }
		}
	}
	cout<<ans;
	return 0;
}
