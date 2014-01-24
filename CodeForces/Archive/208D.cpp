#include <iostream>
using namespace std;
int b[1000];
int main()
{
	int n,a[1000];
	int p[100];
	int v = 0;
	int l=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=5;i++) cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		v+=a[i];
		l = 5;
		while(v>=p[1])
		{
			/*for(int j=5;j>=1;j--)
			{
				if(v>=p[j])
				{
					l = j;
					break;
				}
			}*/
			if(v<p[l]) l--;
			if(v<p[l]) l--;
			if(v<p[l]) l--;
			if(v<p[l]) l--;
			if(l>=1)
			{
				b[l]++;
				v-=p[l];
			}
			else
			{
				break;
			}
		}	
	}
	
	for(int i=1;i<=5;i++) cout<<b[i]<<" ";
	cout<<endl;
	cout<<v;

	return 0;
}