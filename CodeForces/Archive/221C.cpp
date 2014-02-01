#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100001],b[100001];
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[i] = a[i];
	}
	int c = 0;
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		if(a[i]!=b[i]) c++;
	}
	if(c==2 || c==0) cout<<"YES"<<endl;
	else cout<<"NO";
	return 0;
}