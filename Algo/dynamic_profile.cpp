/*
	E-olimp.ru - 482;
	Taskname: Plitki
*/
#include <iostream>
using namespace std;
int a[100][100];
int d[100][100];
int n,m;
bool bit(int v,int pos)
{
	return (v&int(1<<pos));
}
void rec(int p1,int p2,int i)
{
	if(i>=n) {d[p1][p2]++;return;}
	if(bit(p1,i)==0)
	{
		if(bit(p2,i)==0)
		{
			rec(p1,(p2|(1<<i)),i+1);
		}
		if(i+1<n && bit(p1,i+1)==0)
		{
			rec(p1,p2,i+2);
		}
	}
	else rec(p1,p2,i+1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int x;
	while(cin>>x)
	{
		if(x==-1) break;
		memset(a,0,sizeof(a));
		memset(d,0,sizeof(d));
		n = 3;
		m = x;
		a[1][0] = 1;
		
		for(int i=0;i<(1<<n);i++)
		{
			rec(i,0,0);
		}
		for(int i=2;i<=m+1;i++)
		{
			for(int p1=0;p1<(1<<n);p1++)
			{
				for(int p2=0;p2<(1<<n);p2++)
				{
					a[i][p2] += a[i-1][p1]*d[p1][p2];
				}
			}
		}
		/*
		for(int i=0;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		*/
		cout<<a[m+1][0]<<endl;
	}
	/*for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	} */
	
	return 0;
}