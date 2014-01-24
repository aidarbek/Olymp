#include <iostream>
#include <math.h>
using namespace std;
int a[100][100];
int abs1(int x)
{
 	if(x<0) x*=-1;
 	return x;
}
int main()
{                                    
	int r1,c1,r2,c2;
	int lad, slon, kral;
	cin>>r1>>c1>>r2>>c2;
	if(r1==r2 || c1==c2)
	{
	  lad = 1;
	}
	else lad = 2;
	int x,y;
	x    = abs1(r1-r2);
	y    = abs1(c1-c2);
	kral = max(x,y)-min(x,y)+min(x,y);
	if(x==y) slon = 1;
	else
	{
		a[r1][c1] = 1;
		for(int i=c1;i<=8;i+=2) a[r1][i] = 1;
		for(int i=c1;i>=1;i-=2) a[r1][i] = 1;
 		for(int i=r1;i<=8;i++)
 		{
 			for(int j=1;j<=8;j++)
 			{
 				if(a[i-1][j-1] || a[i-1][j+1])
 				{
 				 	a[i][j] = 1;
 				}
 			}
 		}
 		for(int i=r1;i>=1;i--)
 		{
 			for(int j=1;j<=8;j++)
 			{
 				if(a[i+1][j+1] || a[i+1][j-1])
 				{
 				 	a[i][j] = 1;
 				}
 			}
 		}
 		if(!a[r2][c2]) slon = 0;
 		else slon = 2;
	}
	cout<<lad<<" "<<slon<<" "<<kral;     
	return 0;
}
