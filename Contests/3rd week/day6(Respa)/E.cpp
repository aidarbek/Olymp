#include <iostream>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main()
{
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int s;
	int x = 0;
	cin>>s;
	if(s<10) cout<<s;
	else cout<<s-1;
	return 0;
}