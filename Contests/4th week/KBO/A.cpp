#include <iostream>
#include <vector>
using namespace std;

long long q,l,r;
long long c=0;  
void go(long long v, long long mul)
{
	if(q%mul!=0)
	{
		return;	
	}
	if((v<l || v>r) && v!=0) return;   
	if(mul==q) {c++;} 
	for(int i=1;i<=9;i++)
	{
		go(v*10+i, mul*i);
	}
	
}
int main()
{
	freopen("juba.in","r",stdin);
	freopen("juba.out","w",stdout);
	cin>>q>>l>>r;
	go(0, 1);
	cout<<c;
	return 0;
}