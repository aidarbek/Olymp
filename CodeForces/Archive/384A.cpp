#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;
char a[1001][1001];
int  n;
int  c = 0;
int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;       
	memset(a,'.',sizeof(a));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]!='C')
			{         				
				if(a[i-1][j]!='C' && a[i+1][j]!='C' &&a[i][j+1]!='C' &&a[i][j-1]!='C')
				{
					c++;
					a[i][j] = 'C';
				}
			}
		}                 	
	}
	cout<<c<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<a[i][j];
		}
		cout<<endl;
	}
	return 0;
}