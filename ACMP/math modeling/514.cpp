#include <iostream>
using namespace std;
int a[100000];
int i = 1;
int last;
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int k;
	cin>>k;
	while(k>0)
	{
		k-=i;
		if(k>=0) last = i;
		i++;
	}   
	cout<<last;
	return 0;
}