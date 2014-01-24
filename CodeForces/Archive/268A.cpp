#include <iostream>
using namespace std;
bool u[1000];
int main()
{
	int n;
	int h[1000],a[1000];
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i]>>a[i];
	}
	int c =0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				if(h[i]==a[j] && !u[j]) {c++;}
			}
		}
	}
	cout<<c;
	return 0;
}