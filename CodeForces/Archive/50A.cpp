#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	int n,m;
	cin>>n>>m;
	int n1=n,m1=m;
	n = max(n1,m1);
	m = min(n1,m1);
	if(n%2==1)
		 sum += m/2;
	sum+=n/2*m;
	cout<<sum;
	return 0;
}