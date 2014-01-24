#include <iostream>
#include <map>
using namespace std;
map<int,bool> m;
int n;
int a[300001];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		while(m[a[i]]==1) 
		{	
			a[i]++;
		}
		m[a[i]] = 1;
		cout<<a[i]<<endl;
	}
	return 0;
}