#include <iostream>
#include "dsu.h"
using namespace std;
	  	
int main()
{
	DSU d;
	int a,b,f;
	cin>>a;
	for(int i=1;i<=a;i++)
	{
		
		cin>>b; 
		if(i==1) f = b;
		d.insert_set(b);
		d.union_set(f,b);
	}
	cin>>a>>b;
	if(d.in_one_set(a,b)) cout<<a<<" and "<<b<<" are in one set\n";
	else cout<<a<<" and "<<b<<" are not in one set\n"; 
	cout<<"The size of the set, in which "<<a<<" is "<<d.size_set(a)<<"\n";
	cout<<"The size of the set, in which "<<b<<" is "<<d.size_set(b)<<"\n";
	return 0;
}