/*
	Queries:
		S l r   - sum on the segment l,r
		U l r   - equal on the all elements of the segment l,r
		A l r v - add to the all elements of the segment l,r
		? v     - value of the v'th element
		
*/
#include <iostream>
#include <math.h>
using namespace std;
int a[1000000];
int sum[1000];
int add[1000];
char c;
int l,r,v;
int n,m;
int buf;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m;
	//memset(mul,1,sizeof(mul));
	int size = (int)sqrt(n+.0)+1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum[i/size] +=a[i];
	}
	cerr<<size<<endl;
	for(int i=0;i<size;i++) cerr<<sum[i]<<" ";
	cout<<endl;
	for(int i=1;i<=m;i++)
	{
		cin>>c;
		buf = 0;
		if(c=='S')
		{
			cin>>l>>r;
			for(int j=l;j<=r;j++)
			{
				if(j%size==0 && j+size-1<=r)
				{
					buf+=sum[j/size];
					j+=size;
				}
				else buf+=a[j];			
			}
			cout<<buf<<endl;
		}
		if(c=='A')
		{
			cin>>l>>r>>v;
			for(int j=l;j<=r;j++)
			{
				if((j)%size==0 && j+size-1<=r)
				{
					sum[j/size]+=v*size;
					add[j/size]+=v;
					j+=size;                  				
				}
				else
				{
					sum[j/size]+=v;
					a[j]+=v;
				}
			}
		}
		if(c=='?')
		{
			cin>>v;
			cout<<a[v]+add[v/size];
		}
	}
	return 0;
}