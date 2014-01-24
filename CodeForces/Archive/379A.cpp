#include <iostream>
using namespace std;
int main()
{
	int a,b;
	int ans =0;
	cin>>a>>b;
	while(a>=b)
	{
		if(a-b>=0)
		{
			a-=b;
			a++;
			ans+=b;
		}			
	}
	cout<<ans+a;
	return 0;
}