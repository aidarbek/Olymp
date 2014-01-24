#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{
	freopen("cocai.in","r",stdin);
	freopen("cocai.out","w",stdout);
	int a[10][10];
	for(int i=1;i<=2;i++)
	{	
		for(int j=1;j<=2;j++)
		{
			cin>>a[i][j];
		}
	}
	int a1,b1,c1,d1;
	double val;
	double mx = -9999;
	int rot = 0;
	a1 = a[1][1];
	b1 = a[1][2];
	c1 = a[2][1];
	d1 = a[2][2];
	mx =  (a1/c1)+(b1/d1);
	for(int i=1;i<=3;i++)
	{
		a1 = a[1][1];
		b1 = a[1][2];
		c1 = a[2][1];
		d1 = a[2][2];
		a[1][1] = c1;
		a[1][2] = a1;
		a[2][1] = d1;
		a[2][2] = b1;
		
		a1 = a[1][1];
		b1 = a[1][2];
		c1 = a[2][1];
		d1 = a[2][2];
		double vl = (a1/c1)+(b1/d1);
		if(vl>=mx)
		{
			mx = vl;
			rot = i;
		} 
	}
	cout<<rot;
	return 0;
}
