#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int  n;
char c[1000][1000];
int max1 =-9999999;
int min1 = 9999999;
int found = 0;
int all;
void go(int x,int y)
{
	if(c[x][y]=='K') found++;

}
int main()
{
	freopen("koki.in","r",stdin);
	freopen("koki.out","w",stdout);
	cin>>n;
	int sx,xy;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>c[i][j];
			if(c[i][j] =='P')
			{
				sx = i;
				sy = j;
			}
			if(c[i][j] =='K')
			{
				all++;
			}
		}	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			
		}	
	}
	go(sx,sy);

	return 0;
}