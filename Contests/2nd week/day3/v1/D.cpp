#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int  n,m;
char a[100][100];
int  b[100];
int  k;
int  w;
int  offset;
int main()
{
	freopen("painting.in","r",stdin);
	freopen("painting.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		w = m/k;
		int between = m%k;
		for(int j=0;j<k;j++)
		{
			 cin>>b[j];
			 offset = (w-b[j])/2;   			 
			 int from = offset + w*j+1;
			 if(j>0) from += between*j;
			 int to   = from+b[j]-1;
			 for(int y=from;y<=to;y++)
			 {
			 	a[i][y] = 'i';
			 }
			 
		}
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!='i' && a[i][j]!='.') a[i][j] = '.';
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}