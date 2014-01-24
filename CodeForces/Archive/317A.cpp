#include <iostream>
using namespace std;
int main()
{
	long long int x,y,m,last_sum = 0;
	long long int x1,y1;
	cin>>x>>y>>m;
	int i=0;
	while(x<m && y<m)
	{
		i++;
		x1 = x;
		y1 = y;
		x = max(x1,y1);
		y = x1+y1;
		
		if(i>=10000000) {cout<<-1;return 0;}
	}
	if(i-1<0) cout<<0;
	else cout<<i;
	return 0;
}