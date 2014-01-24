#include <iostream>
using namespace std;
int main()
{
	freopen("input.txt", "r",stdin);
	freopen("output.txt", "w",stdout);
	int n;
	cin>>n;
	if(n==3 || n==4 || n==6) cout<<"YES";
	else cout<<"NO";

	return 0;
}
