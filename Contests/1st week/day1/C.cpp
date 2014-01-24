#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
char s[1000];
char a[10000][10000];
char ch;
char f;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int step = 0;
	cin>>s;
	int n;
	memset(a,'.',sizeof(a));
	n = strlen(s);
	int x = 3, y = 3;
	for(int i=0;i<n;i++)
	{
		step++;
		if(step%3==0) f = '*';
		else f = '#';
		ch = s[i];
		a[x][y] = ch;
		
		if(a[x][y+2]  !='*') a[x][y+2] = f;
		if(a[x+1][y+1]!='*') a[x+1][y+1]= f;
		if(a[x-1][y+1]!='*') a[x-1][y+1] = f;
		if(a[x-1][y-1]!='*') a[x-1][y-1] = f;
		if(a[x+1][y-1]!='*') a[x+1][y-1] = f;
		if(a[x+2][y]  !='*') a[x+2][y] = f;
		if(a[x-2][y]  !='*') a[x-2][y] = f;
		if(a[x][y-2]  !='*') a[x][y-2] = f;	
		y+=4;
	}
	y-=2;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=y;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}
