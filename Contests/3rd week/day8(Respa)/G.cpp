#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include "dist.h"
using namespace std;
/*double dist(int x,int y)
{
	return sqrt((x-3)*(x-3)+(y-5)*(y-5));
}
void start(){}
void finish(int abc,int abc1){}*/
int main()
{ 
	freopen("out","w",stdout);
    //10 0000 0000 10^9
	start();
	int x=0,y=0;
	int ansx = x, ansy = y;
	bool found = 0;
	double d = dist(0,0);
	double d1 = (d*d);
	double check;
	int j;
	int start = d1*-1;
	for(int i=start;i<=d1;i++)
	{
		for(j=start;j<=d1;j++)
		{
			if(i*i+j*j==d1)
			{
				ansx = i;
				ansy = j;
			}
		}
	}
	finish(ansx,ansy);
	cout<<ansx<<" "<<ansy;
	return 0;
}

