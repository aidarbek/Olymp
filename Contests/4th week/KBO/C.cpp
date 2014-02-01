#include <iostream>
using namespace std;

int a[100][100];
int b[100][100];
int c[100][100];
int x,y;
int n,m;
int s,t;
int k=7777777;

void mul()
{
	int sum = 0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sum = 0;
			for(int k=1;k<=n;k++)
			{
				sum+=a[i][k]*b[k][i];	
			}
			c[i][j] = sum;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j] = c[i][j];
		}
	}
}
void binpow (int n) 
{
    if(n==0||n==1) return;
	if (n % 2 == 1)
	{
		binpow(n-1);
		mul();
	}	
	else 
	{
		/*
			int b = binpow (a, n/2);
			return b * b; 
		*/
		binpow(n/2);
		mul();
	}
}
int main()
{
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		a[x][y]++;
		b[x][y] = a[x][y];
	}
	cin>>s>>t;
	binpow(k);
	cout<<a[s][t];
	return 0;
}