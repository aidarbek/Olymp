#include <iostream>
using namespace std;
int main()
{
	freopen("G.in","w",stdout);
	int m=100000, n=20;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;i++)
	{	
	     for(int j=1;j<=m;j++)
	     {
	     	if(j==m) cout<<"*";
	     	else cout<<".";
	     }
	     cout<<endl;
	}
	for(int i=1;i<=n;i++)
	{	
	     for(int j=1;j<=m;j++)
	     {
	     	if(j==1) cout<<"*";
	     	else cout<<".";
	     }
	     cout<<endl;
	}
	return 0;
}